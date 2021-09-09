#include <bits/stdc++.h>
#include "BinaryTreeNode.cpp"

using namespace std;

template <typename T>
BinaryTreeNode<T>* takeInput() {
    int rootData;

    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<T> *root = new BinaryTreeNode<T> (rootData);

    queue<BinaryTreeNode<T>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<T> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1) {
            BinaryTreeNode<T> *leftChild = new BinaryTreeNode<T> (leftChildData);
            frontNode -> left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<T> *rightChild = new BinaryTreeNode<T> (rightChildData);
            frontNode -> right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

template <typename T>
void printTreeLevelWise(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }

    queue<BinaryTreeNode<T>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<T> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout << frontNode -> data << " : ";

        if(frontNode -> left != NULL) {
            cout << "L" << frontNode -> left -> data << " ";
            pendingNodes.push(frontNode -> left);
        }
        if(frontNode -> right != NULL) {
            cout << "R" << frontNode -> right -> data;
            pendingNodes.push(frontNode -> right);
        }
        cout << endl;
    }
}


template <typename T>
BinaryTreeNode<T>* removeLeafNode(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> left == NULL && root -> right == NULL) {
        delete root;
        return NULL;
    }
    if(root -> left -> left == NULL && root -> left -> right == NULL) {
        BinaryTreeNode<T> *temp = root -> left;
        root -> left = NULL;
        delete temp;
    }
    if(root -> right -> left == NULL && root -> right -> right == NULL) {
        BinaryTreeNode<T> *temp = root -> right;
        root -> right = NULL;
        delete temp;
    }
    removeLeafNode(root -> left);
    removeLeafNode(root -> right);
    
    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    printTreeLevelWise(root);

    cout << endl;

    root = removeLeafNode(root);
    printTreeLevelWise(root);
    return 0;
}