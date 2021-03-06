#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top = -1;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = (int *)malloc(sizeof(int) * this->size);
    }
    int isEmpty()
    {
        if (this->top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull()
    {
        if (this->top == this->size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(int data)
    {
        if (this->isFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            this->top++;
            this->arr[this->top] = data;
        }
    }

    int pop()
    {
        if (!this->isEmpty())
        {
            int valToReturn = this->arr[this->top];
            this->top--;
            return valToReturn;
        }
        else
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
    }

    int topR()
    {
        if (!this->isEmpty())
        {
            return this->arr[this->top];
        }
        return -1;
    }
};
Stack *s = new Stack(100);

void insertSorted(int val)
{
    if (s->arr[s->top] > val || s->isEmpty())
    {
        s->push(val);
    }
    else
    {
        int x = s->pop();
        insertSorted(val);
        s->push(x);
    }
}

int main(int argc, char const *argv[])
{

    insertSorted(10);
    insertSorted(20);
    insertSorted(5);
    insertSorted(30);
    insertSorted(1);

    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;
    cout << s->pop() << endl;

    return 0;
}