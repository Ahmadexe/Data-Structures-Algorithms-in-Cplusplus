#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int top = -1;
        vector<char> arr;
        int size;

        Stack(int size)
        {
            this->size = size;
        }

        int isEmpty()
        {
            if (this->top == -1)
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int isFull()
        {
            if (this->top == this->size - 1)
            {
                return 1;
            }else{
                return 0;
            }
        }

        void push(char data)
        {
            if (this->isFull())
            {
                cout<<"Stack overflow"<<endl;
            }
            else{
                this->top++;
                this->arr.push_back(data);
            }
        }

        char pop()
        {
            if (!this->isEmpty()){
                int valToReturn = arr[top];
                this->top--;
                return valToReturn;
            }
            else{
                cout<<"Stack underflow"<<endl;
                return '\0';
            }
        }
};
Stack* s = new Stack(5);

int palindrome(string str)
{
    int flag = 1;
    for (int i = 0; i < str.size(); i++)
    {
        s->push(str[i]);
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != s->pop())
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{

    cout<<palindrome("civic");


    return 0;
}