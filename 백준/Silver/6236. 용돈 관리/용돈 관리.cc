#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int minK = 0;
vector<int> money;

void solution()
{
	int first = minK;
	int last = 1000000000;
	int K = last;

	while (first <= last)
	{
		int count = 0;
		int mid = (first + last) / 2;
		int balance = 0;

		for (int i = 0; i < N; i++)
		{
			int today = money[i];
			if (balance >= today)
				balance -= today;
			else
			{
				count++;
				balance = mid - today;
			}
		}
		if (count <= M)
		{
			K = min(mid, K);
			last = mid - 1;
		}
		else
			first = mid + 1;
	}

	cout << K;
}



int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		money.push_back(data);
		minK = max(minK, data);
	}

	solution();
}