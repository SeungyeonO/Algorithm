#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> value;

void solution()
{
	int good = 0;
	for (int i = N-1; i >= 0; i--)
	{
		int first = 0;
		int last = N - 1;
		int target = i;

		while (first < last)
		{
			if (last == target)
			{
				last--;
				if (first == last)
					break;
			}
			if (first == target)
			{
				first++;
				if (first == last)
					break;
			}

			int sum = value[first] + value[last];

			if (sum == value[target])
			{
				good++;
				break;
			}

			else if (sum > value[target])
				last--;

			else
				first++;
		}
	}

	cout << good;
}



int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		value.push_back(data);
	}
	sort(value.begin(), value.end());

	solution();
}