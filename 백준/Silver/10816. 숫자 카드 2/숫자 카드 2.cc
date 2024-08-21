#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int upperBound(int arr[], int size, int data)
{
	int first = 0;
	int last = size - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (arr[mid] == data)
			first = mid + 1;
		else if (arr[mid] > data)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return first;
}

int lowerBound(int arr[], int size, int data)
{
	int first = 0;
	int last = size - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (arr[mid] == data)
			last = mid - 1;
		else if (arr[mid] > data)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return last;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int N, M;

	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int data;
		cin >> data;
		cout <<abs(upperBound(arr, N, data) - lowerBound(arr, N, data)) - 1 << ' ';
	}

	return 0;
}