#include <iostream>
#include <cstdlib>//Эта бибилиотека отвечает за работу рандома
#include <vector>
#include <time.h>//Использование системного времени
#include <string>
#include <map>
#include <windows.h>

using namespace std;

namespace liter
{
    string y_number_is = "Your number is ";
    string summ_numbers = "Your summ numbers is ";
    string lose = "YOU LOOOOOOSER!!!";
    string win = "You WIN!";
    string new_or_stop = "Enter 'y' for new number or 'n' for stop game!";
    string comp_num = "Computer number is ";
    string comp_summ_numbers = "Computer summ numbers is ";
    string comp_lose = "NOW COMPUTER BADDEST THAN HUMAN!!!";
    string comp_win = "Now... Computer best than human...";
    string p2_win = "p2 WIN!!!";
    string p2_lose = "p2 lost";
    string comp_or_p2 = "Enter 'c' if computer or 'p' for player 2!";
}//Литеры вывода сообщений

void gen_chislo(vector<int> & summ_game, int & sum_vec);
void summ_chislo(vector<int> & summ_game, int & sum_vec);
void summ_comp_num(vector<int> & summ_comp, int & sum_vec_comp);
bool check_num(int & sum_vec);
void print(string stroka, int num);
void print(string stroka);
vector<int> summ_game;//Хранит числа выпавшие игроку
int sum_vec = 0;//Хранит в себе сумму всех чисел из вектора
vector<int> summ_comp = {0, 1, 1, 2, 14, 22, 76};//Хранит числа выпавшие компьютеру
int sum_vec_comp = 0;//Хранит в себе сумму всех чисел из вектора

int main()
{
    srand((unsigned) time(NULL));//Помогает рандому получать числа.
    gen_chislo(summ_game, sum_vec);

    

    return 0;

}//Эта функция генирирует новое число

void gen_chislo(vector<int> & summ_game, int & sum_vec)
{
    int rand_chislo = 0;//Получает рандомное число
    char vybor;//переменная выбора игрока
    while(vybor != 'n')
    {
        rand_chislo = 2 + rand()%13;
        summ_game.push_back(rand_chislo);
        print(liter::y_number_is, rand_chislo); //Вывод фразы yni и числа
        summ_chislo(summ_game, sum_vec);
        print(liter::summ_numbers, sum_vec); //Вывод фразы ysni и общего числа
        //блок if отвечает за проверку суммы
        if (check_num(sum_vec))
        {
            break; //выход из цикла
        }
        else
        {
            do
            {
                print(liter::new_or_stop);
                cin >> vybor;
            }
            while(vybor != 'y' && vybor != 'n');
        }
    }
}


void summ_chislo(vector<int> & summ_game, int & sum_vec)
{
    sum_vec = 0;
    for(int i = 0; i< summ_game.size();i++)
    {
        sum_vec += summ_game.at(i);
    }
}//Эта функция суммирует числа в векторе.

//Выводит на консоль строку и число
void print(string stroka, int num)
{
    cout<<stroka<<" "<<num<<endl;
}

//Выводит на консоль строку
void print(string stroka)
{
    cout<<stroka<<endl;
}

bool check_num(int & sum_vec)
{
    if (sum_vec > 21)
        {
            print(liter::lose); //Вывод фразы "You LOSE"
            return true;
        }
        else if(sum_vec == 21)
        {
            print(liter::win); //Вывод фразы "You WIN"
            return true;
        }
        else
        {
            return false;
        }
}//Функция проверяет сумму чисел на равность числу 21

void summ_comp_num(vector<int> & summ_comp, int & sum_vec_comp)
{
    sum_vec_comp = 0;
    for(int number : summ_comp)
    {
        sum_vec_comp += number;
    }
}//Эта функция суммирует числа компьютера в векторе.