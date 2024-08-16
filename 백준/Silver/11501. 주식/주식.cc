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


        int maxPos = N - 1;
        long long profit = 0;
        
        for (int k = N - 1; k >= 0; k--)
        {
            if (stock[k] > stock[maxPos])
            {
                maxPos = k;
                continue;
            }
            profit += (stock[maxPos] - stock[k]);
        }

        cout << profit << endl;
        delete[] stock;
    }

    return 0;
}