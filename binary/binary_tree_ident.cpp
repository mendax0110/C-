// include the header file
#include <bits/stdc++.h>

// use the standard namespace
using namespace std;

// define the node structure
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// function to check if two trees are identical
bool isIdentical(node *root1, node *root2)
{
    // if both trees are empty
    if (root1 == NULL && root2 == NULL)
        return true;
    // if both trees are non-empty
    if (root1 != NULL && root2 != NULL)
    {
        // check if the data of both roots is same and data of left and right
        // subtrees are also same
        return (root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
    }
    // if none of the above conditions is true then trees are not identical
    return false;
}

// main function
int main()
{
    // create the first tree
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);

    // create the second tree
    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(4);
    root2->left->right = new node(5);

    // check if the trees are identical
    if (isIdentical(root1, root2))
        cout << "Both trees are identical";
    else
        cout << "Trees are not identical";

    return 0;
}

