#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};

Node* root = NULL;

void insert(int data)
{
    Node *cur = new Node;
    cur->data = data;
    cur->left = NULL;
    cur->right = NULL;
    if (!root)
    {
        root = cur;
    }
    else
    {
        Node *p = new Node;
        p = root;
        Node* temp = new Node;
        while (p != NULL)
        {
            if (p->data < data)
            {
                temp = p;
                p = p->right;
            }
            else
            {
                temp = p;
                p = p->left;
            }
        }
        p = cur;
        if (p->data > temp->data){
            temp->right = p;
        }
        else {
            temp->left = p;
        }
    }
}

void inOrder(Node* x)
{
    if (!x)
    {
        return;
    }
    inOrder(x->left);
    cout<<x->data<<" ";
    inOrder(x->right);
}

int main(int argc, char const *argv[])
{

    insert(30);
    insert(20);
    insert(50);
    insert(70);
    insert(40);
    insert(60);
    Node* z = root;
    inOrder(z);
    return 0;
}