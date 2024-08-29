#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int N, M;
int From, To, Max = 0;
vector<pair<int, int>> bridges[10001];
bool visited[10001];


void DFS(int from, int mid)
{
	for (int i = 0; i < bridges[from].size(); i++)
	{
		if (!visited[bridges[from][i].first] && bridges[from][i].second >= mid)
		{
			visited[bridges[from][i].first] = true;
			DFS(bridges[from][i].first, mid);
		}
	}
}


void solution()
{
	int low = 0;
	int high = Max;
	int mid = (low + high) / 2;

	while (low <= high)
	{
		for (int i = 1; i <= N; i++)
		{
			visited[i] = false;
		}
		
		mid = (low + high) / 2;
		visited[From] = true;
		DFS(From, mid);
		if (visited[To])
			low = mid + 1;
		else
			high = mid - 1;
	}

	cout << high;
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;

		bridges[from].push_back(make_pair(to, weight));
		bridges[to].push_back(make_pair(from, weight));

		Max = max(Max, weight);
	}

	cin >> From >> To;

	solution();

}