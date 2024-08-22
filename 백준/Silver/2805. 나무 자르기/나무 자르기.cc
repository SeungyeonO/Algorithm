#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;

int solution(int trees[])
{
	int start = 0;
	int end = trees[N-1];
	int max = 0;

	while (start <= end)
	{
		long long sum = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < N; i++)
		{
			if ((trees[i] - mid) > 0)
				sum += trees[i] - mid;
		}

		if (sum == M)
			return mid;
		else if (sum > M)
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

	int* trees = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> trees[i];
	}
	sort(trees, trees + N);

	cout << solution(trees);

	delete[] trees;

	return 0;
}