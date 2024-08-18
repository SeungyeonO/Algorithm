#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int N, K;
    cin >> N >> K;


    if (N <= K)
    {
        cout << 0;
        return 0;
    }

    vector<int> sensorPos;
    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        sensorPos.push_back(data);
    }
    sort(sensorPos.begin(), sensorPos.end());

    priority_queue<int> distance;

    for (int i = 1; i < N; i++)
    {
        int prev = i - 1;
        distance.push(sensorPos[i] - sensorPos[i-1]);
    }

    int totalDistance = sensorPos[N-1] - sensorPos[0];
    for (int i = 0; i < K - 1; i++)
    {
        totalDistance -= distance.top(); 
        distance.pop();
    }

    cout << totalDistance;
    return 0;
}