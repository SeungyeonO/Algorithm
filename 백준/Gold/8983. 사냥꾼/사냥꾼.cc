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

	int first = 0;
	int last = N - 1;
	int bound = first;
	
	for (int i = 1; i < M; i++)
	{
		int target = (position[i] + position[i - 1]) / 2;
		int prevBound = bound;
		while (first <= last)
		{
			int mid = (first + last) / 2;

			if (animals[mid].first > target)
				last = mid - 1;
			else
			{
				first = mid + 1;
				bound = max(mid + 1, bound);
			}
		}

		for (int j = prevBound; j < bound; j++)
		{
			if (abs(position[i - 1] - animals[j].first) + animals[j].second <= L)
				count++;
		}
		first = bound;
		last = N - 1;
	}

	for (int i = bound; i < N; i++)
	{
		if (abs(position[M-1] - animals[i].first) + animals[i].second <= L)
			count++;
	}

	cout << count;
}

bool CompareAnimal(pair<int, int> A, pair<int, int> B)
{
	return (A.first < B.first);
}

bool ComparePosition(int A, int B)
{
	return (A < B);
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

	sort(position.begin(), position.end(), ComparePosition);

	for (int i = 0; i < N; i++)
	{	
		int X, Y;
		cin >> X >> Y;
		animals.push_back(make_pair(X, Y));
	}

	sort(animals.begin(), animals.end(), CompareAnimal);

	solution();
}