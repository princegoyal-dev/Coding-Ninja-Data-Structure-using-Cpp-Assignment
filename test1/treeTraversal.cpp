#include <bits/stdc++.h>

using namespace std;

class Node {
    public :
        int data;
        Node *left, *right;

        Node(int data) {
            this -> data = data;
            left = right = NULL;
        }
};


void postorder(Node *root) {
    if(root == NULL) {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << endl;
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root -> left);
    cout << root -> data << endl;
    inorder(root -> right);
}
void preorder(Node *root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << endl;
    preorder(root -> left);
    preorder(root -> right);
}

int main() {
    Node *root = new Node(4);
    root -> left = new Node(2);
    root -> right = new Node(6);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(7);

    preorder(root);

    inorder(root);

    postorder(root);
    
    return 0;
}