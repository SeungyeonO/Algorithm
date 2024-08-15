#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long int L, R;
    cin >> L >> R;

    long RRemain = R;
    long LRemain = L;

    int count = 0;
    for (int i = 9; i >= 0; i--)
    {
        long digits = pow(10, i);

        if (RRemain / digits == 0)
            continue;

        int RShare = RRemain / digits;
        int LShare = LRemain / digits;

        if (RShare != LShare)
            break;

        else if (RShare == 8)
            count++;

        RRemain = RRemain % digits;
        LRemain = LRemain % digits;
    }

    cout << count;

    return 0;
}