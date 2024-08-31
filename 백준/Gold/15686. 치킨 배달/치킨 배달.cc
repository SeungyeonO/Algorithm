#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int N, M;
int map[50][50];

vector<pair<int, int>> chicken;
pair<int, int> pickedChicken[13];
vector<pair<int, int>> house;
int chickenDistance = 1000000000;


void input()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
				chicken.push_back(make_pair(i, j));
			else if (map[i][j] == 1)
				house.push_back(make_pair(i, j));
		}
	}
}

int calcDistance(pair<int, int> A, pair <int, int> B)
{
	return abs(A.first - B.first) + abs(A.second - B.second);
}

void calcChickenDistance()
{
	int totalDistance = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int minDistance = 1000000000;
		for (int j = 0; j < M; j++)
		{
			int distance = calcDistance(pickedChicken[j], house[i]);
			minDistance = min(distance, minDistance);
		}
		totalDistance += minDistance;
	}
	chickenDistance = min(totalDistance, chickenDistance);
}

void pickChicken(int index, int count)
{
	if (count == M)
	{
		calcChickenDistance();
		return;
	}

	for (int i = index; i < chicken.size(); i++)
	{
		pickedChicken[count] = chicken[i];
		pickChicken(i + 1, count + 1);
	}
}

void solution()
{
	pickChicken(0, 0);
	cout << chickenDistance;
}

int main()
{
	input();
	solution();
}