#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        int* stock = new int[N];
        for (int j = 0; j < N; j++)
            cin >> stock[j];


        long long maxPos = -1;
        long long profit = 0;
        while (maxPos != 0 && maxPos != N - 1)
        {
            int start = maxPos + 1;
            maxPos = start;
            for (int k = start; k < N; k++)
            {
                if (stock[k] >= stock[maxPos])
                    maxPos = k;
            }
            
            profit += (maxPos - start) * stock[maxPos];
            for (int k = start; k < maxPos; k++)
                profit -= stock[k];

        }

        cout << profit << endl;
        delete[] stock;
    }

    return 0;
}