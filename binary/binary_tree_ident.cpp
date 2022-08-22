#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data)  {
        this->data = data;
        left = right = NULL;
    }
};

bool isIdentical(Node *root1, Node *root2)  {
    if(root1 == NULL && root2 == NULL) return true;
    if((root1 && !root2) || (!root1 && root2)) return false;
    if(root1->data != root2->data) return false;
    return  isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

int main()  {
 /*
        1
       / \
      2   2
     / \ / \
    4  5 6  7
 */
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << isIdentical(root, root);

    return 0;
}
