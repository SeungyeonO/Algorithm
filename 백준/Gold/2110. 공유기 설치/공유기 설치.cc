#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> house;

void solution()
{
	int start = 1;
	int end = house[N-1];

	int max = 1;

	while (start <= end)
	{
		int prevHouse = house[0];
		int sum = 1;
		int mid = (start + end) / 2;

		for (int i = 1; i < N; i++)
		{
			if (house[i] - prevHouse >= mid)
			{
				sum++;
				prevHouse = house[i];
			}
		}

		if (sum >= M)
		{
			start = mid + 1;
			max = mid;
		}
		else
			end = mid - 1;
	}

	cout << max;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		house.push_back(data);
	}
	sort(house.begin(), house.end());

	solution();
}