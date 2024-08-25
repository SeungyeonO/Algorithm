#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> value;
vector<int> sum;

void solution()
{
	int target = N-1;
	while (target >= 0)
	{
		for (int i = target - 1; i >= 0; i--)
		{
			int first = 0;
			int last = sum.size() - 1;

			while (first <= last)
			{
				int mid = (first + last) / 2;
				int sumOfThree = value[i] + sum[mid];
				if (value[target] == sumOfThree)
				{
					cout << value[target];
					return;
				}
				else if (value[target] > sumOfThree)
					first = mid + 1;
				else
					last = mid - 1;
			}
		}
		target--;
	}

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

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i; j < N - 1; j++)
		{
			sum.push_back(value[i] + value[j]);
		}
	}
	sort(sum.begin(), sum.end());

	solution();
}