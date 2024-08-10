#include <iostream>
using namespace std;

struct nodeType {
    int data;
    nodeType* prev;
    nodeType* next;
};

class Deque {
private:
    nodeType* head;
    nodeType* tail;
    int size;

public:
    Deque();
    void DQRemove();
    void DQAdd(int data);
    int DQPeek();
    void moveRight();
    void moveLeft();
    ~Deque();
};




int main() {
    int size, num, data;
    cin >> size >> num;

    Deque deque;
    for (int i = 1; i <= size; i++)
    {
        deque.DQAdd(i);
    }

    int minMoveNum = 0;
    for (int i = 0; i < num; i++)
    {
        int moveCount = 0;
        cin >> data;
        while (deque.DQPeek() != data)
        {
            deque.moveRight();
            moveCount++;
        }

        if (moveCount > size/2)
            minMoveNum += (size - moveCount);
        else
            minMoveNum += moveCount;

        deque.DQRemove();
        size--;

    }

    cout << minMoveNum;

    return 0;
}



Deque::Deque()
{
    size = 0;
    head = NULL;
    tail = NULL;
}

Deque::~Deque()
{
    while (size != 0)
    {
        DQRemove();
    }
}

void Deque::DQRemove()
{
    nodeType* RNode = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;

    delete RNode;

    size--;
}

void Deque::DQAdd(int data)
{
    nodeType* newNode = new nodeType;
    newNode->data = data;

    if (size == 0)
    {
        head = newNode;
        tail = newNode;
        head->prev = tail;
        tail->next = head;
    }

    else
    {
        tail->next = newNode;
        newNode->next = head;
        newNode->prev = tail;
        tail = newNode;
        head->prev = tail;

    }

    size++;
}

int Deque::DQPeek()
{
    return head->data;
}

void Deque::moveRight()
{
    head = head->next;
    tail = tail->next;
}

void Deque::moveLeft()
{
    head = head->prev;
    tail = tail->prev;
}