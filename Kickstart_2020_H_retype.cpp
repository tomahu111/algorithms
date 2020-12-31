// Kickstart_2020_H_retype.cpp 
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043adc7

#include <iostream>
#include <vector>
using namespace std;

long long min(long long one, long long two)
{
    if (one > two)
    {
        return two;
    }
    else
    {
        return one;
    }
}

long long solve(long long n, long long curr, long long swor)
{
    return min(curr + n, 2*curr - 2*swor + n);
}

int main()
{
    long long T, N, K, S;
    vector<long long> answ;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> K >> S;
        answ.push_back(solve(N, K, S));
    }
    for (int i = 0; i < T; i++)
    {
        cout << "Case #" << i + 1 << ": " << answ[i] << "\n";
    }
}
