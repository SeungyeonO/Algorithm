#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int,int>> XA;
    long long totalPeople = 0;
    for (int i = 0; i < N; i++)
    {
        int town, people;
        cin >> town >> people;

        XA.push_back(make_pair(town, people));
        totalPeople += people;
    }
    sort(XA.begin(), XA.end());


    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += XA[i].second;
        if (sum >= (totalPeople + 1) / 2)
        {
            cout << XA[i].first;
            break;
        }
    }

    return 0;
}