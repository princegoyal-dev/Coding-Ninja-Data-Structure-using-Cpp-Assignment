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
int height(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + max(height(root -> left), height(root -> right));
}

template <typename T>
bool checkBalanced(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return false;
    }
    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);
    if(abs(rightHeight - leftHeight) == 0 || abs(rightHeight - leftHeight) == 1) {
        return true;
    } else return false;
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
//1 2 3 4 5 -1 -1 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1
//1 2 3 4 5 -1 -1 -1 -1 -1 -1
//1 2 3 4 5 -1 -1 6 -1 7 -1 -1 -1 -1 -1
//1 2 3 4 5 -1 8 6 -1 7 -1 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    printTreeLevelWise(root);

    cout << endl;

    bool result = checkBalanced(root);
    cout << result;

    return 0;
}