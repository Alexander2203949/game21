#include <iostream>
#include <cstdlib> //Эта библиотека отвечает за работу рандома.
#include <vector>
#include <string> 
#include<time.h> /*данная библиотка помогает рандому 
синхронизироваться по системному времени*/

using namespace std;

namespace liter
{
    string y_number_is = "Your number is";
    string summ_numbers = "Your summ numbers is";
    string lose = "You LOSE";
    string win = "You WIN!";
    string new_or_stop = "Enter 'y' for new number or 'n' for stop game!";
} //Литеры вывода сообщений

void gen_chislo(vector<int> & summ_game, int & sum_vec);
void summ_chislo(vector<int> & summ_game, int & sum_vec);
bool check_num(int & sum_vec);
void print(string stroka, int num);
void print(string stroka);
vector<int> summ_game;// хранит числа выпавшие игроку
int sum_vec = 0; //хранит сумму всех чисел из вектора

int main()
{
    srand((unsigned) time(NULL)); // помогает рандому получать числа.
    gen_chislo(summ_game, sum_vec);
    

    return 0;

}
//эта функция генерирует новое число.
void gen_chislo(vector<int> & summ_game, int & sum_vec)
{
    int rand_chislo = 0; // получает рандомное число
    char vybor; //переменная выбора игрока.
    while(vybor != 'n')
    {
        rand_chislo = rand()%10;
        summ_game.push_back(rand_chislo);
        print(liter::y_number_is, rand_chislo);// вывод фразы "Your number is" и числа
        summ_chislo(summ_game, sum_vec);
        print(liter::summ_numbers, sum_vec); //вывод фразы "Your summ numbers is" и общей суммы
        //блок if отвечает за проверку суммы
        if (check_num(sum_vec))
        {
            break; //выход из цикла
        }
        else
        {
            print(liter::new_or_stop);//вывод фразы "Enter 'y' for new number or 'n' for stop game!"
            cin >> vybor;
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

//вывожин на консоль строку и число
void print(string stroka, int num)
{
    cout << stroka << " " << num << endl;
}

//выводит на консоль строку
void print(string stroka)
{
    cout << stroka << endl;
}

//функция проверяет сумму чисел на равность числу 21
bool check_num(int & sum_vec)
{
    if (sum_vec > 21)
    {
        print(liter::lose); //вывод фразы "You LOSE"
        return true;
    }
    else if(sum_vec == 21)
    {
        print(liter::win);// вывод фразы "You WIN!"
        return true;
    }
    else
    {
        return false;
    }
}