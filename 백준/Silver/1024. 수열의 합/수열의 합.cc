#include <iostream>
using namespace std;

int  main() {
    int N, L;
    cin >> N >> L;

    int sequenceNum = L;
    int startNum;
    int share;
    int found = false;
    while (true)
    {   
        if (N < L*(L-1)/2)
            break;

        int num = N * 2;
        if (num % sequenceNum == 0)
        {
            share = num / sequenceNum;
            startNum = (share - (sequenceNum - 1));
            if (startNum < 0)
                break;
            else if (startNum % 2 == 0)
            {
                found = true;
                break;
            }

        }
        sequenceNum++;
    }

    if (found && sequenceNum <= 100)
    {
        for (int i = 0; i < sequenceNum; i++)
            cout << startNum / 2 + i << " ";
    }

    else
        cout << -1;

    return 0;

}