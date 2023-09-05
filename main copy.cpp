#include <iostream>
#include <cstdlib>  //этф библиотека отвечает за работу рандому
#include <vector>
#include<time.h> //данная библиотека помогает рандому синхроризироваться по системному времени
#include <string>
#include <map>

using namespace std;
namespace liter
{
    std::string y_number_is = "Your number is";
    std::string summ_numbers = "Your summ number is";
    std::string lose = "You LOSE";
    std::string win = "You WIN!";
    std::string new_or_stop = "Enter 'y' for new number or 'n' for stop game!";
    string comp_number = "Computer number is";
    string comp_sum_numbers = "Computer summ number is";
    string comp_lose = "You LOSE";
    string comp_win = "Computer WIN!";
    string second_player_win = "2 player WIN!";
    string second_player_lose = "2 player LOSE";
    string check_player = "Enter 'c' if computer or 'p' second player";

};//литеры вывода сообщений
void gen_chislo(vector<int> & summ_game, int & sum_vec);
void summ_chislo(vector<int> & summ_game, int & sum_vec);
bool check_num(int & sum_vec);
void print(string stroka,int num);//выводит 
void print(string stroka);
vector<int> summ_game; //храник числа выпавшие игроку
int sum_vec = 0;//хранит сумму всех чисел из вектора



int main()
{
    srand((unsigned) time(NULL));
    gen_chislo(summ_game, sum_vec);
    

    return 0;

}

//эта функция генерирует новое число
void gen_chislo(vector<int> & summ_game, int & sum_vec)
{
    int rand_chislo = 0;//получает рандомное число
    char vybor; //переменная выбора игрока
    while(vybor != 'n')
    {
        rand_chislo = 2 + rand()%10;
        summ_game.push_back(rand_chislo);
        print(liter::y_number_is,rand_chislo);//вывод фразы Your number is и числа
        summ_chislo(summ_game, sum_vec);
        print(liter::summ_numbers,sum_vec);//вывод фразы Your summ numbers is и общей суммы чисел
        //блок if отвечает за проверку суммы
        if (check_num(sum_vec))
        {
            break;//отвечает за выход из цикла
        }
        else
        {
            do
            {
                print(liter::new_or_stop);//вывод фразы Enter 'y' for new number or 'n' for stop game!
                cin >> vybor;
            }while(vybor != 'y' && vybor != 'n');

        }
    }


}
//эта функция суммирует числа в векторе
void summ_chislo(vector<int> & summ_game, int & sum_vec)
{
    sum_vec = 0;
    for(int i = 0; i< summ_game.size();i++)
    {
        sum_vec += summ_game.at(i);
    }
}
//выводит на консоль строку и число
void print(string stroka,int num)
{
    cout<<stroka<<" "<<num<<endl;
}
//выводи на консоль строку
void print(string stroka)
{
    cout<<stroka<<endl;
}
//функция проверяет сумму чисел на равность числу 21
bool check_num(int & sum_vec)
{
    if (sum_vec > 21)
    {
        print(liter::lose);//вывод фразы You LOSE
        return true;
    }
    else if(sum_vec == 21)
    {
        print(liter::win);//вывод фразы You WIN!
        return true;
    }
    else
    {
        return false;
    }
}









