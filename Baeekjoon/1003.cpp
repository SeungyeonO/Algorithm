#include <iostream>
using namespace std;



int main() {

    int tryNum;
    cin >> tryNum;


    int* arrayValue = new int [tryNum];
    for (int index = 0; index < tryNum; index++)
        cin >> arrayValue[index];


    for (int i = 0; i < tryNum; i++)
    {
        int N = arrayValue[i];
        int count0, count1;

        if (N == 0)
        {
            count1 = 0;
            count0 = 1;
        }

        else if (N == 1)
        {
            count1 = 1;
            count0 = 0;
        }

        else
        {
            int prev = 0, cur = 1;
            for (int j = 1; j < N; j++)
            {
                int temp = prev;
                prev = cur;
                cur += temp;
            }
            count1 = cur;
            count0 = prev;
        }

        cout << count0 << " " << count1 << endl;
    }

    delete[] arrayValue;
    return 0;
}
