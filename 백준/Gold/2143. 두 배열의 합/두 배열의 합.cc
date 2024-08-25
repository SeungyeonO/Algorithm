#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T,N,M;
vector<int> A, B, sumA, sumB;

void solution()
{
	long long count = 0;

	for (int i = 0; i < sumA.size(); i++)
	{
		int first = 0;
		int last = sumB.size() - 1;

		while (first <= last)
		{
			int mid = (first + last) / 2;
			int sum = sumA[i] + sumB[mid];
			
			if (sum == T)
			{
				count += upper_bound(sumB.begin(), sumB.end(), sumB[mid])
					- lower_bound(sumB.begin(), sumB.end(), sumB[mid]);
				break;
			}
			else if (sum > T)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	cout << count;
}



int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> T >> N;

	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		A.push_back(data);
	}

	for (int i = 0; i < N; i++)
	{	
		sumA.push_back(A[i]);
		int prev = A[i];
		for (int j = i+1; j < N; j++)
		{	
			int cur = prev + A[j];
			sumA.push_back(cur);
			prev = cur;
		}
	}
	sort(sumA.begin(), sumA.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int data;
		cin >> data;
		B.push_back(data);
	}

	for (int i = 0; i < M; i++)
	{
		sumB.push_back(B[i]);
		int prev = B[i];
		for (int j = i + 1; j < M; j++)
		{
			int cur = prev + B[j];
			sumB.push_back(cur);
			prev = cur;
		}
	}
	sort(sumB.begin(), sumB.end());

	solution();
}