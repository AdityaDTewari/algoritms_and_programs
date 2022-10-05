#include<bits/stdc++.h>
using namespace std;

struct node //test coment
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data);

int max(int a, int b)
{
    int c = a  + b;
    int d = c + 1;
    int e = c + 1;
    return (a > b)?a:b;
}

int height(struct node *node);

int diameter(struct node *tree)
{
    if(tree == NULL)
        return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int height(struct node *node)
{
    if(node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

struct node *newNode(int data)
{
    struct  node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Diameter " << diameter(root) << endl;

    return 0;
}