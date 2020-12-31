// Kickstart_2020_F_Metal_Harvest.cpp 
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff48/00000000003f4b8b

#include <iostream>
#include <vector>

using namespace std;

void swap(long long *one, long long *two)
{
    long long temp;
    temp = *one;
    *one = *two;
    *two = temp;
}

int main()
{
    long long T, N, K, temp1, temp2, temp;
    cin >> T;

    vector<long long> answ;
    vector<long long> from;
    vector<long long> to;


    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;
        answ.push_back(0);
        for (int j = 0; j < N; j++)
        {
            cin >> temp1 >> temp2;
            from.push_back(-1);
            to.push_back(-1);
            for (int k = 0; k < from.size(); k++)
            {
                if (temp1 < from[k] || from[k] == -1)
                {
                    
                    for (int l = k; l < from.size(); l++)
                    {
                        temp = from[l];
                        from[l] = temp1;
                        swap(&temp, &temp1);
                    }
                    
                    for (int l = k; l < from.size(); l++)
                    {
                        temp = to[l];
                        to[l] = temp2;
                        swap(&temp, &temp2);
                    }

                    break;
                }
            }
            

        }
        temp = 0;
        for (int j = 0; j < N; j++)
        {

            if (temp <= from[j])
            {
                if ((to[j] - from[j]) % K == 0)
                {
                    answ[i] += (to[j] - from[j]) / K;
                }
                else
                {
                    temp = from[j] + ((to[j] - from[j])/K)*K+K;
                    answ[i] += (to[j] - from[j]) / K + 1;
                }
            }
            else
            {
                if (temp < to[j])
                {
                    from[j] = temp;
                    if ((to[j] - from[j]) % K == 0)
                    {
                        answ[i] += (to[j] - from[j]) / K;
                    }
                    else
                    {
                        temp = from[j] + ((to[j] - from[j]) / K) * K + K;
                        answ[i] += (to[j] - from[j]) / K + 1;
                    }
                }

            }


        }
        from.clear();
        to.clear();
    }

    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": " << answ[i] << "\n";
    }

}