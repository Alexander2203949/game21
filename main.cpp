




void summ_comp_num(vector<int> & summ_comp, int & sum_vec_comp);

void summ_comp_num(vector<int> & summ_comp, int & sum_vec_comp)
{
    sum_vec_comp = 0;
    for(int number : summ_comp)
    {
        sum_vec_comp += number;
    }
}//Эта функция суммирует числа компьютера в векторе.
