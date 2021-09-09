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
void printTree(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " : ";
    if(root -> left != NULL) {
        cout << "L" << root -> left -> data << " ";
    }
    if(root -> right != NULL) {
        cout << "R" << root -> right -> data;
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);
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
int countNode(BinaryTreeNode <T> *root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + countNode(root -> left) + countNode(root -> right);
}

template <typename T>
bool isPresent(BinaryTreeNode<T> *root, T value) {
    if(root == NULL) {
        return false;
    }
    if(root -> data == value) {
        return true;
    } else return (isPresent<T>(root -> left, value) || isPresent<T>(root -> right, value));
}

template <typename T>
int height(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + max(height<T> (root -> left), height<T> (root -> right));
}

template <typename T>
void convertToMirror(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }
    convertToMirror(root -> left);
    convertToMirror(root -> right);

    BinaryTreeNode<T> *tempNode = root -> left;
    root -> left = root -> right;
    root -> right = tempNode;
}

template <typename T>
void preOrderPrint(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrderPrint(root -> left);
    preOrderPrint(root -> right);
}

template <typename T>
void postOrderPrint(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }
    postOrderPrint(root -> left);
    postOrderPrint(root -> right);
    cout << root -> data << " ";
}

template <typename T>
void inOrderPrint(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }
    inOrderPrint(root -> left);
    cout << root -> data << " ";
    inOrderPrint(root -> right);
}

//1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 4 5 8 9 3 6 7 
// 4 2 8 5 9 1 6 3 7
// 4 8 9 5 2 6 7 3 1
int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    // printTree<int>(root);
    // cout << endl;
    printTreeLevelWise<int>(root);
    cout << endl;
    cout << countNode(root);
    cout << endl;
    cout << boolalpha << isPresent<int>(root, 9);
    cout << endl;
    cout << height(root);
    cout << endl;
    // convertToMirror(root);
    printTreeLevelWise(root);
    cout << endl;
    preOrderPrint <int>(root);
    cout << endl;
    inOrderPrint <int>(root);
    cout << endl;
    postOrderPrint<int>(root);
    return 0;
}