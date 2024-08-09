#include <iostream>
using namespace std;

bool dfs(int x, int y, bool** field, bool** check, int width, int length);

int main() {

    int tryNum;
    cin >> tryNum;

    while (tryNum != 0)
    {
        tryNum--;
        int width, length, cabbageNum;
        cin >> width >> length >> cabbageNum;

        //실제 밭보다 상하좌우로 한칸씩 더 넓은 배열 생성 - 복잡한 조건문 방지
        bool** field = new bool* [width+2];
        for (int i = 0; i < width+2; i++) {
            field[i] = new bool[length+2];
        }

        bool** check = new bool* [width + 2];
        for (int i = 0; i < width + 2; i++) {
            check[i] = new bool[length + 2];
        }

        for (int i = 0; i < width + 2; i++)
        {
            for (int j = 0; j < length + 2; j++)
            {
                field[i][j] = false;
                check[i][j] = false;
            }
        }



        while (cabbageNum != 0)
        {
            cabbageNum--;
            int x, y;
            cin >> x >> y;

            field[x + 1][y + 1] = 1;
        }

        int wormNum = 0;
        
        for (int i = 1; i < width + 1; i++)
        {
            for (int j = 1; j < length + 1; j++)
            {
                if (field[i][j])
                {
                    if (dfs(i, j, field, check, width+2, length+2)) wormNum++;
                }
            }
        }

        cout << wormNum << endl;

        for (int i = 0; i < width + 2; i++)
        {
            delete[] field[i];
            delete[] check[i];
        }
        delete[] field;
        delete[] check;
    }

    return 0;
}


bool dfs(int x, int y, bool** field, bool** check, int width, int length)
{
    if (check[x][y]) return false;

    check[x][y] = true;

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX >= 0 && nextY >= 0 && nextX <= width - 1 && nextY <= length - 1 && field[nextX][nextY])
            dfs(nextX, nextY, field, check, width, length);
    }


    return true;
}