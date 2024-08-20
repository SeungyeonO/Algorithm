#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    
    long long sum = 0;
    vector<long long> equip;


    for (int i = 0; i < N; i++)
    {
        long long muscleLoss;
        cin >> muscleLoss;

        equip.push_back(muscleLoss);
        sum += muscleLoss;
    }

    if (N % 2 == 1)
    {
        equip.push_back(0);
        N++;
    }
    sort(equip.begin(), equip.end());


    priority_queue<long long> day;
    for (int i = 0; i < (N / 2); i++)
    {
        day.push(equip[i] + equip[N-i-1]);
    }

    cout << day.top();

    return 0;
}