#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int request[10000];

void solution()
{
	int start = 1;
	int end = M;
	int max = 0;

	while (start <= end)
	{
		long long sum = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < N; i++)
		{
			if (request[i] > mid)
				sum += mid;
			else
				sum += request[i];
		}

		if (sum <= M)
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
	cin >> N;

	int sum = 0;
	int maxRequest = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> request[i];
		sum += request[i];
		maxRequest = max(maxRequest, request[i]);
	}
	cin >> M;

	if (sum <= M)
		cout << maxRequest;
	else
		solution();
}