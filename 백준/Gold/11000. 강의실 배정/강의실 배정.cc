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

    vector<pair<int, int>> timeTable;
    priority_queue<int, vector<int>, greater<int>> finishTime;

    for (int i = 0; i < N; i++)
    {
        int S, T;
        cin >> S >> T;
        timeTable.push_back(make_pair(S, T));
    }

    sort(timeTable.begin(), timeTable.end());


    for (int i = 0; i < N; i++)
    {
        finishTime.push(timeTable[i].second);
        if (finishTime.top() <= timeTable[i].first) finishTime.pop();
    }
    
    cout << finishTime.size();
    return 0;
}