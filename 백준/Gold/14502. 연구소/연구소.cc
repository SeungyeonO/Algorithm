#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int N, M;
int map[8][8];
int testMap[8][8];
int WallMap[8][8];
bool visited[8][8];
vector<pair<int, int>> virus;
vector<pair<int, int>> safeRoom;
bool check[64];
int safeRoomNum;
int maxSafeZone = 0;
int num = 0;


void copyMap(int arr1[8][8], int arr2[8][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			arr1[i][j] = arr2[i][j];
	}
}

void input()
{
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int data;
			cin >> data;
			map[i][j] = data;
			if (data == 0)
				safeRoom.push_back(make_pair(i, j));
			else if (data == 2)
				virus.push_back(make_pair(i, j));
		}
	}
	safeRoomNum = safeRoom.size();
	copyMap(testMap, map);
	copyMap(WallMap, map);
}




void DFS(int row, int col)
{

	if (!visited[row][col] && testMap[row][col] == 2)
	{
		visited[row][col] = true;

		int dX[4] = { -1, 1, 0, 0 };
		int dY[4] = { 0, 0, -1, 1 };

		for (int i = 0; i < 4; i++)
		{
			int nextRow = row + dX[i];
			int nextCol = col + dY[i];

			if (nextRow > -1 && nextRow < N && nextCol > -1 && nextCol < M && testMap[nextRow][nextCol] == 0)
			{
				testMap[nextRow][nextCol] = 2;
				num--;
				DFS(nextRow, nextCol);
			}
		}
	}
}


void test()
{
	copyMap(testMap, WallMap);
	num = safeRoomNum - 3;

	for (int i = 0; i < virus.size(); i++)
	{
		DFS(virus[i].first, virus[i].second);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			visited[i][j] = false;
	}

	maxSafeZone = max(maxSafeZone, num);
}


// 0인 곳에서 3개를 '조합' 해 벽 세우기
void makeWall(int index, int count)
{
	if (count == 3)
	{
		test();
		return;
	}

	for (int i = index; i < safeRoomNum; i++)
	{
		if (check[i] != true)
		{
			check[i] = true;
			int row = safeRoom[i].first;
			int col = safeRoom[i].second;
			WallMap[row][col] = 1;
			makeWall(i, count + 1);
			WallMap[row][col] = 0;
			check[i] = false;
		}
	}
}

void solution()
{
	makeWall(0, 0);
	cout << maxSafeZone;
}

int main()
{
	input();
	solution();
}