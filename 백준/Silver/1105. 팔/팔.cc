#include <iostream>
#include <string>
using namespace std;

int main()
{
    string L, R;
    cin >> L >> R;

    int count = 0;
    if (L.size() == R.size())
    {
        for (int i = 0; i < L.size(); i++)
        {
            if (L[i] != R[i])
                break;

            if (L[i] == '8')
                count++;
        }
    }
    cout << count;
}