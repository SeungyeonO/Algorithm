#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int solution(int cables[])
{
	long long start = 1;
	long long end = cables[N-1];
	long long max = 0;

	while (start <= end)
	{
		long long sum = 0;
		long long mid = (start + end) / 2;

		for (int i = 0; i < N; i++)
		{
			sum += cables[i] / mid;
		}

		if (sum >= M)
		{
			start = mid + 1;
			max = mid;
		}
		else
			end = mid - 1;
	}

	return max;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> N >> M;

	int* cables = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> cables[i];
	}
	sort(cables, cables + N);

	cout << solution(cables);

	delete[] cables;

	return 0;
}