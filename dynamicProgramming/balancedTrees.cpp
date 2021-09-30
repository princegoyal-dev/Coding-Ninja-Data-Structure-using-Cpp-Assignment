#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode *left, *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = right = NULL;
        }
        ~BinaryTreeNode() {
            delete left;
            delete right;
        }
};

BinaryTreeNode<int>* input() {
    int rootData;
    cin >> rootData;
    if(rootData != -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1) {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            frontNode -> left = leftChild;
            pendingNodes.push(leftChild);
        }

        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            frontNode -> right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}


int calculate(int *arr, int height) {
    if(height <= 1) {
        return 1;
    }
    if(arr[height] != -1) {
        return arr[height];
    }
    int modValue = (int)pow(10, 9) + 7;
    int option1 = 2 * calculate(arr, height - 1) * calculate(arr, height - 2);
    int option3 = calculate(arr, height - 1) * calculate(arr, height - 1);

    arr[height] = option1 + option3;
    return option1 + option3;
}
int main() {
    int h;
    cin >> h;

    int *arr = new int[h + 1];
    for(int i = 0; i <= h; i++) {
        arr[i] = -1;
    }
    cout << calculate(arr, h);

    return 0;
}