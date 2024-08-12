#include <iostream>
#include <cmath>
using namespace std;

char relationship[50][50];
int check[50][50];

void dfs(int myNum, int other, int size)
{   
    if (check[myNum][myNum] == 1)
    {
        for (int i = 0; i < size; i++)
            if (relationship[myNum][i] == 'Y')
                check[other][i] = 1;
    }

    else
    {
        check[myNum][myNum] == 1;
        for (int i = 0; i < size; i++)
            if (relationship[myNum][i] == 'Y')
            {
                check[other][i] = 1;
                dfs(i, myNum, size);
            }  
    }  
}

int  main() {


    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> relationship[i][j];
        }
    }

    int maxNum = 0;
    for (int i = 0; i < num; i++)
    {
        dfs(i, i, num);
        int count = -1;
        for (int j = 0; j < num; j++)
        {
            if (check[i][j] == 1)
                count++;
        }
        maxNum = max(maxNum, count);
    }

    cout << maxNum;
    return 0;
}