#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;

    int count = 1;
    char* color = new char[N];

    cin >> color[0];
    for (int i = 1; i < N; i++)
    {
        cin >> color[i];
        if (color[i] != color[i - 1])
            count++;
    }

    if (count % 2 == 0)
        cout << (count + 2) / 2;
    else
        cout << (count + 1) / 2;

    return 0;
}