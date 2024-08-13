#include <iostream>
#include <string>
using namespace std;

string king, nextKing, stone, nextStone;


void move(string& pos, string action)
{
    for (int i = 0; i < 2; i++)
    {
        if (action[i] == 'L')
            pos[0]--;
        else if (action[i] == 'R')
            pos[0]++;
        else if (action[i] == 'B')
            pos[1]--;
        else if (action[i] == 'T')
            pos[1]++;
        else
            break;
    }
}

bool checkPos(string& cur, string next)
{
    if (next[0] > 'H' || next[0] < 'A' || next[1] > '8' || next[1] < '1')
        return false;
    cur = next;
    return true;
}

int main()
{
    int moveNum;

    cin >> king >> stone >> moveNum;

    for (int i = 0; i < moveNum; i++)
    {
        nextKing = king;
        nextStone = stone;

        string action;
        cin >> action;

        move(nextKing, action);
        if (stone[0] == nextKing[0] && stone[1] == nextKing[1])
        {
            move(nextStone, action);
            if (checkPos(stone, nextStone))
                king = nextKing;
        }
        else
            checkPos(king, nextKing);
    }

    cout << king << endl;
    cout << stone << endl;
    return 0;
}