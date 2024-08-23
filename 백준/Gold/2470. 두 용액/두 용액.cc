#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> value;

void solution()
{
	int num1, num2;
	int min = 2000000001;

	int first = 0; 
	int last = N - 1;

	while (first < last)
	{
		int sum = value[first] + value[last];
		if (abs(sum) < abs(min))
		{
			num1 = value[first];
			num2 = value[last];
			min = sum;

			if (min == 0)
				break;
		}

		if (sum < 0)
			first++;
		else
			last--;
	}
	
	if (num1 > num2)
		cout << num2 << ' ' << num1;
	else
		cout << num1 << ' ' << num2;
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