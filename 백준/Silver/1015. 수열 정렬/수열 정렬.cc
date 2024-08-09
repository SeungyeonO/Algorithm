#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;

    int* unsortedArr = new int[size];
    int* sortedArr = new int[size];

    for (int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        unsortedArr[i] = data;
        
        bool insert = false;
        for (int j = 0; j < i; j++)
        {
            if (data < sortedArr[j])
            {
                for (int p = i; p > j; p--)
                    sortedArr[p] = sortedArr[p - 1];
                sortedArr[j] = data;
                insert = true;
                break;
            }
        }
        if (!insert)
            sortedArr[i] = data;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; i < size; j++)
        {
            if (sortedArr[j] == unsortedArr[i])
            {
                sortedArr[j] = 0;
                cout << j << " ";
                break;
            }
        }
    }

    delete[] unsortedArr;
    delete[] sortedArr;

    return 0;
}