#include <iostream>
#include <cmath>
using namespace std;

using Matrix = int[50][50];

int  main() {
    Matrix rectangle;
    int length, width;
    cin >> length >> width;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
            scanf("%1d", &rectangle[i][j]);
    }

    int size = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int num = rectangle[i][j];
            for (int k = j; k < width; k++)
            {
                if (rectangle[i][k] == num && k - j <= length - i - 1)
                {
                    if (rectangle[i + k - j][j] == num && rectangle[i + k - j][k] == num)
                        size = max(size, (k - j + 1) * (k - j + 1));
                }
            }
        }
    }

    cout << size;
    return 0;
}