#include <iostream>
#include <cstdlib>
#include <vector>
#include<time.h>




using namespace std;
void gen_chislo(vector<int> & summ_game, int & sum_vec);
void summ_chislo(vector<int> & summ_game, int & sum_vec);
vector<int> summ_game;
int sum_vec = 0;

int main()
{
    srand((unsigned) time(NULL));
    gen_chislo(summ_game, sum_vec);
    

    return 0;

}

void gen_chislo(vector<int> & summ_game, int & sum_vec)
{
    int rand_chislo = 0;
    char vybor;
    while(vybor != 'n')
    {
        rand_chislo = rand()%10;
        summ_game.push_back(rand_chislo);
        cout << "Your number is " << rand_chislo << endl;
        summ_chislo(summ_game, sum_vec);
        cout << "Your summ numbers is " << sum_vec << endl;
        if (sum_vec > 21)
        {
            cout << "You LOSE"<< endl;
            break;
        }
        else if(sum_vec == 21)
        {
            cout << "You WIN!"<< endl;
            break;
        }
        else
        {
            cout << "Enter 'y' for new number or 'n' for stop game!" << endl;
            cin >> vybor;
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
}