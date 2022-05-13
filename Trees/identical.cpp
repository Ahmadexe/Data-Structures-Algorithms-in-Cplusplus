#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {   
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert(Node* root, int val)
{
    if (!root->left || !root->right)
    {
        Node* p = new Node(val);
        if (val < root->data && !root->left)
        {
            root->left = p;
            return;
        }
        else if (p->data > root->data && !root->right)
        {
            root->right = p;
            return;
        }
    }
    if (val > root->data)
        {
            insert(root->right, val);
        }
        else
        {
            insert(root->left, val);
        }
    
}

void inOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main(int argc, char const *argv[])
{

    
    Node* root1 = new Node(40);
    insert(root1,30);
    insert(root1,10);
    insert(root1,15);
    insert(root1,50);
    // cout<<endl;
    inOrder(root1);


    return 0;
}