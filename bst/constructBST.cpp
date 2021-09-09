//program to construct BST from a sorted array
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
        ~BinaryTreeNode() {
            if(left != NULL) {
                delete left;
            }
            if(right != NULL) {
                delete right;
            }
        }
};

BinaryTreeNode<int>* constructBST(int *arr, int si, int ei) {
    if(si > ei) {
        return NULL;
    }
    int midIndex = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (arr[midIndex]);
    root -> left = constructBST(arr, si, midIndex - 1);
    root -> right = constructBST(arr, midIndex + 1, ei);
    
    return root;
}

void printTreeLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
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

int main() {
    int arr[] = {1,3, 4, 6, 7, 9, 12, 13, 25, 67};
    int size = sizeof(arr) / sizeof(arr[0]);

    BinaryTreeNode<int> *root = constructBST(arr, 0, size - 1);
    printTreeLevelWise(root);
    return 0;
}
