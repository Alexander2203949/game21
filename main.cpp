#include <iostream>
#include <cstdlib>  //Эта библиотека отвечает за работу рандома
#include <vector>
#include<string>
#include<map>
#include<windows.h>
#include<time.h> //Данная библиотека помогает рандому
 //синхронизироваться по
  //системному времени

using namespace std;
namespace liter
{
    string y_number_is = "Your number is";
    string summ_numbers = "Your summ numbers is";
    string lose = "You LOSE";
    string win  =  "You WIN!";
    string new_or_stop = "Enter 'y' for new number or 'n' for stop game!";
    string comp_number = "Computer number is";
    string comp_sum_numbers="Computer summ numbers is";
    string comp_lose = "Computer LOSE";
    string comp_win  =  "Computer WIN!";
    string second_player_win="2 player WIN";
    string second_player_lose="2 player LOSE";
    string check_player = "Enter 'c' if computer or 'p' second player";

} //Литеры вывода сообщений

void gen_chislo(vector<int> & summ_game, int & sum_vec);
void summ_chislo(vector<int> & summ_game, int & sum_vec);
void summ_chislo_comp(vector<int> & summ_comp, int & sum_vec);//
bool check_num(int & sum_vec);
void print(string stroka, int num);
void print(string stroka);
vector<int> summ_game; //Хранит числа выпавшиие игроку
int sum_vec = 0; //Хранит сумму всех чисел из вектора
vector<int> summ_comp; //
int sum_vec_comp=0;//

int main()
{
   
    srand((unsigned) time(NULL)); //Помогает рандому получать числа
    gen_chislo(summ_game, sum_vec); 
  
    
    return 0;

}
//Эта функция генерирует новое число
void gen_chislo(vector<int> & summ_game, int & sum_vec)
{
    int rand_chislo = 0;  //Получает рандомное число
    char vybor; // Эта переменная выбора игрока
    while(vybor != 'n')
    {
        rand_chislo = 2+rand()%13;
        summ_game.push_back(rand_chislo);
        print(liter::y_number_is,rand_chislo);//вывод фразы "Your number is" и числа
        summ_chislo(summ_game, sum_vec);
        print(liter::summ_numbers, sum_vec);//Вывод фразы "Your summ numbers is " и общей суммы 
        //блок if отвечает за проверку суммы 
        if (check_num(sum_vec))
        {
            break;//Выход из цикла 
        }
        else 
        {
            
            do
            {
                print(liter::new_or_stop);//Вывод фразы "Enter 'y' for new number or 'n' for stop game!"
                cin >> vybor;
            }while(vybor != 'y' && vybor !='n');
          
        }
    }  
}
//Эта функция суммирует числа в векторе 
void summ_chislo(vector<int> & summ_game, int & sum_vec)
{
    sum_vec = 0;
    for(int i = 0; i< summ_game.size();i++)
    {
        sum_vec += summ_game.at(i);
    }
}

//Выводит на консоль строку и число
void print(string stroka, int num)
{
    cout <<stroka <<" "<<num <<endl;
}
//Выводит на консоль строку 
void print(string stroka)
{
    cout << stroka <<endl;
}

//эта фунуция проверяет сумму чисел на равность числу 21
bool check_num(int & sum_vec)
{
    if (sum_vec > 21)
    {
        print(liter::lose);//Вывод фразы "You LOSE"
        return true;
    }
    else if(sum_vec == 21)
    {
        print(liter::win);//Вывод фразы "You WIN!"
        return true;
    }
    else
    {
        return false;
    }
}


//TEST_______________________________________________________________

void summ_chislo_comp(vector<int> & summ_comp, int & sum_vec_comp)//
{
    
    for(auto var : summ_comp)
    {
        sum_vec_comp += var;
        cout<<var<<" "<<endl;
    }
}
