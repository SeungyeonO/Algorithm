#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int N, M;
int robotRow, robotCol, robotDirection;
int map[50][50];
int cleaned = 0;


void input()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> N >> M;

	cin >> robotRow >> robotCol >> robotDirection;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}


void decidePosition(int& row, int& col, int direction)
{
	switch (direction)
	{
	case(0):
		row -= 1;
		break;
	case(1):
		col += 1;
		break;
	case(2):
		row += 1;
		break;
	case(3):
		col -= 1;
		break;
	}
}



void clean(int row, int col)
{
	if (map[row][col] == 1)
		return;

	if (map[row][col] == 0)
	{
		map[row][col] = -1;
		cleaned++;
	}

	bool move = false;
	int nextDirection = robotDirection;
	do
	{
		nextDirection = (nextDirection + 3) % 4;

		int nextRow = row;
		int nextCol = col;

		decidePosition(nextRow, nextCol, nextDirection);

		if (map[nextRow][nextCol] == 0)
		{
			robotDirection = nextDirection;
			clean(nextRow, nextCol);
			return;
		}
	} while (nextDirection != robotDirection);


	int nextRow = row;
	int nextCol = col;
	decidePosition(nextRow, nextCol, (robotDirection + 2) % 4);
	clean(nextRow, nextCol);
}


void solution()
{
	clean(robotRow, robotCol);
	cout << cleaned;
}


int main()
{
	input();
	solution();
}