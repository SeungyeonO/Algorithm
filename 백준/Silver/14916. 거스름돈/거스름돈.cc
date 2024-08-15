#include <iostream>
using namespace std;

int main()
{
    int change;
    cin >> change;

    int fiveWon = change / 5;
    int remain = change % 5;
    int twoWon;

    while (fiveWon >= 0)
    {
        twoWon = remain / 2;
        if (remain % 2 == 0)
        {
            cout << fiveWon + twoWon;
            return 0;
        }
        fiveWon--;
        remain += 5;
    }

    cout << -1;
    return 0;
}