#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;


int N, M, K;
int A[10][10];
vector<int> map[10][10];
int livingtreeNum = 0;

void input()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	livingtreeNum = M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
			map[i][j].push_back(5);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int row, col, age;
		cin >> row >> col >> age;
		map[row - 1][col - 1].push_back(age);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].size() > 2)
			{
				sort(map[i][j].begin() + 1, map[i][j].end());
			}
		}
	}

}


void springAndSummer()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int size = map[i][j].size();
			if (size > 1)
			{
				int shortage = size;
				for (int k = 1; k < size; k++)
				{
					if (map[i][j][k] > map[i][j][0])
					{
						shortage = k;
						break;
					}
					map[i][j][0] = map[i][j][0] - map[i][j][k];
					map[i][j][k] = map[i][j][k] + 1;
				}

				for (int k = shortage; k < size; k++)
				{
					map[i][j][0] += (map[i][j][k] / 2);
				}

				for (int k = 0; k < size - shortage; k++)
				{
					map[i][j].pop_back();
					livingtreeNum--;
				}
			}
		}
	}
}


void reproduce(int row, int col)
{
	int dR[8] = { 0,0,-1,1,-1,1,1,-1 };
	int dC[8] = { -1,1,0,0,-1,1,-1,1 };

	for (int j = 0; j < 8; j++)
	{
		int nextRow = row + dR[j];
		int nextCol = col + dC[j];

		if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < N)
		{
			map[nextRow][nextCol].push_back(1);
			livingtreeNum++;
		}
	}
}


void fall()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int size = map[i][j].size();
			if (size > 1)
			{
				for (int k = 1; k < size; k++)
				{
					if (map[i][j][k] % 5 == 0)
						reproduce(i, j);
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int size = map[i][j].size();
			if (size > 2)
			{
				sort(map[i][j].begin() + 1, map[i][j].end());
			}
		}
	}
}



void winter()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j][0] = map[i][j][0] + A[i][j];
		}
	}
}


void solution()
{
	for (int i = 0; i < K; i++)
	{
		springAndSummer();
		fall();
		winter();
	}
	cout << livingtreeNum;
}


int main()
{
	input();
	solution();
}