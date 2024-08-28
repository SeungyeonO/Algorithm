#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N, L;
vector<int> position;
vector<pair<int, int>> animals;

void solution()
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int distance = abs(position[j] - animals[i].first) + animals[i].second;
			if (distance <= L)
			{
				count++;
				break;
			}
		}
	}
	cout << count;
}



int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> M >> N >> L;

	for (int i = 0; i < M; i++)
	{
		int data;
		cin >> data;
		position.push_back(data);
	}



	for (int i = 0; i < N; i++)
	{	
		int X, Y;
		cin >> X >> Y;
		animals.push_back(make_pair(X, Y));
	}

	solution();
}