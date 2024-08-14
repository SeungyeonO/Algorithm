#include <iostream>
using namespace std;

int main()
{
    double X, Y;
    cin >> X >> Y;

    int Z = (Y * 100) / X;

    if (Z >= 99)
        cout << -1;
    
    else
    {
        double first = 0;
        double last = X;
        int mid = (first + last) / 2;
        bool found = false;

        while (!found)
        {
            int _Z = ((Y + mid) * 100) / (X + mid);
            if (_Z == Z)
            {
                first = mid + 1;
                mid = (first + last) / 2;


            }
            else
            {
                last = mid;
                mid = (first + last) / 2;
            }

            if (first == last)
                found = true;

        }
        cout << mid;
    }
    return 0;
}