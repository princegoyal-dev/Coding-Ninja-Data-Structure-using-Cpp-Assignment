#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

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
void printNodeWithoutSiblings(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }
    if(root -> left == NULL && root -> right != NULL) {
        cout << root -> right -> data << " ";
    }
    if(root -> left != NULL && root -> right == NULL) {
        cout << root -> left -> data << " ";
    }
    printNodeWithoutSiblings(root -> left);
    printNodeWithoutSiblings(root -> right);
}

//1 2 3 4 5 6 -1 -1 8 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    printTreeLevelWise(root);

    cout << endl;
    printNodeWithoutSiblings(root);
    return 0;
}