#include <iostream>
#include <string>
#include <cstdlib> //Эта библиотека отвечает за работу рандома
#include <vector>
#include <list>
#include <time.h> //Данная библиотека помогает рандому синхронизироваться по системе arvei
#include <map>
#include <windows.h>

using namespace std;

namespace liter
{
    string your_number_is = "Your number is ";
    string summ_numbers = "Your summ numbers is ";
    string lose = "You LOSE";
    string win = "You WIN!";
    string new_or_stop = "Enter 'y' for new number or 'n' for stop game!";
    string comp_number = "Computer number is";
    string comp_summ_numbers = "Computer summ numbers is";
    string comp_lose = "Computer LOSE";
    string comp_win = "Computer WIN!";
    string second_player_win = "2 player WIN!";
    string second_player_lose = "2 player LOSE";
    string check_player = "Enter 'c' if computer or 'p' second player!";
};

void gen_chislo(vector<int> & summ_game, int & sum_vec);
void summ_chislo(vector<int> & summ_game, int & sum_vec); 
bool check_numm(int & sum_vec);
void print(string stroca, int numm);
void print(string stroca);
vector<int> summ_game; //хранит в себе числа выповшие игроку
int sum_vec = 0; //хранит сумму всех чисел из вектора
vector<int> summ_comp;
int sum_vec_comp = 0;
void summ_chislo_comp(vector<int> & summ_comp, int & sum_vec_comp);

int main()
{
    srand((unsigned) time(NULL)); //помогает рандому получать числа
    gen_chislo(summ_game, sum_vec); 
    return 0;

} //эта функция генирирует новое число 

void gen_chislo(vector<int> & summ_game, int & sum_vec)
{
    int rand_chislo = 0; //получает рандомное число
    char vybor; //эта переменная выбора игрока
    while(vybor != 'n')
    {
        rand_chislo = 2 + rand()%13;
        summ_game.push_back(rand_chislo);
        print(liter::your_number_is, rand_chislo); //вывод фразы "Your number is" и числа 
        summ_chislo(summ_game, sum_vec); 
        print(liter::summ_numbers, sum_vec); //вывод фразы "Your summ numbers is " и общей суммы
        if (check_numm(sum_vec))
        {
            break; //выход из цикла
        }
        else
        {
            do
            {
                print(liter::new_or_stop);//вывод фразы "Enter 'y' for new number or 'n' for stop game!"
                cin >> vybor;

            }
            while(vybor != 'y' && vybor != 'n');
            
        }
    }    
}

void summ_chislo(vector<int> & summ_game, int & sum_vec) //эта функция сумирует числа в векторе
{
    sum_vec = 0;
    for(int i = 0; i< summ_game.size();i++)
    {
        sum_vec += summ_game.at(i);
    }
}

//выводит на консоль строку и число
void print(string stroca, int numm)
{
    cout << stroca <<" "<< numm << endl;
}

//выводит на консоль строку
void print(string stroca)
{
    cout << stroca << endl;
}

//проверяет сумму чисел на равность числу 21
bool check_numm(int & sum_vec)
{
    if (sum_vec > 21)
    {
        print(liter::lose); //вывод фразы lose "You LOSE"
        return true;
    }  
    else if(sum_vec == 21) 
    {
        print(liter::win); //вывод фразы "You WIN!"
        return true;
    }
    else
    {
        return false;
    }
}

void summ_chislo_comp(vector<int> & summ_comp, int & sum_vec_comp)
{
    sum_vec_comp = 0;
    for(int number : summ_comp)
    {
        sum_vec_comp += number;
    }
}

