#include <iostream>
using namespace std;

int  main() {
    int N, L;
    cin >> N >> L;

    for (int i = L; i < 101; i++)
    {
        int startNum = N / i - (i - 1) / 2;
        if (startNum >= 0 && N == (2 * startNum + i - 1) * i / 2)
        {
            for (int j = 0; j < i; j++)
                cout << startNum + j << " ";
            return 0;
        }
    }
    cout << "-1";
    return 0;

}