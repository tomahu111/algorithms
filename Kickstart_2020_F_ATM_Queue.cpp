// Kickstart_2020_F_ATM_Queue.cpp
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4ed8

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    long long T, N, X, min, temp;
    cin >> T;
    vector<long long>* answ = new vector<long long>[T];
    vector<long long> queue;
    
    for (int i = 0; i < T; i++)
    {
        cin >> N >> X;
        min = INT32_MAX;
        for (long long j = 0; j < N; j++)
        {
            cin >> temp;
            if (temp % X == 0)
            {
                temp = temp / X;
            }
            else
            {
                temp = temp / X + 1;
            }
            if (temp < min)
            {
                min = temp;
            }
            queue.push_back(temp);
        }
        temp = 0;
        while (temp!=INT32_MAX)
        {
            temp = INT32_MAX;
            for (long long j = 0; j < N; j++)
            {
                if (queue[j] == min)
                {
                    answ[i].push_back(j+1);
                }
                else if (queue[j] > min && queue[j] < temp)
                {
                    temp = queue[j];
                }
            }
            min = temp;
        }
        queue.clear();
    }


    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ":";
        for (long long j = 0; j < answ[i].size(); j++)
        {
            cout << " " << answ[i][j];
        }
        cout << "\n";
    }
    delete[] answ;
}
