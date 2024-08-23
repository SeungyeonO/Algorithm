#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> value;

void solution()
{
	int num1 = value[1], num2 = value[0];
	int min = num1 + num2;

	for (int i = 2; i < N; i++)
	{
		int sum = value[i] + value[i - 1];
		if (abs(sum) < abs(min))
		{
			num1 = value[i];
			num2 = value[i - 1];
			min = sum;

			if (min == 0)
				break;
		}
	}
	
	if (num1 > num2)
		cout << num2 << ' ' << num1;
	else
		cout << num1 << ' ' << num2;
}

bool compare(const int& a, const int& b)
{
	return (abs(a) > abs(b));
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
	sort(value.begin(), value.end(), compare);

	solution();
}