#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left, *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = right = NULL;
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

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;

    if(rootData == -1) {
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

int findDepth(BinaryTreeNode<int> *root, int k) {
    if(root == NULL) {
        return -1;
    }
    int dist = -1;
    if(root -> data == k || findDepth(root -> left, k) >= 0 || findDepth(root -> right, k) >= 0) {
        return dist + 1;
    }
    return dist;
}

void printNodesDistanceToKHelper(BinaryTreeNode<int> *root, int distance) {
    if(root == NULL || distance < 0) {
        return;
    }
    if(distance == 0) {
        cout << root -> data << " ";
        return;
    }
    printNodesDistanceToKHelper(root -> left, distance - 1);
    printNodesDistanceToKHelper(root -> right, distance - 1);
}

int printNodesDistanceToK(BinaryTreeNode<int> *root, int nodeData, int distance) {
    if(root == NULL) {
        return -1;
    }
    if(root -> data == nodeData) {
        printNodesDistanceToKHelper(root, distance);
        return 0;
    }
    int leftCheck = printNodesDistanceToK(root -> left, nodeData, distance);

    if(leftCheck != -1) {
        if(leftCheck + 1 == distance) {
            cout << root -> data << endl;
        } else {
            printNodesDistanceToKHelper(root -> right, distance - leftCheck - 2);
        }
        return 1 + leftCheck;
    }
    int rightCheck = printNodesDistanceToK(root -> right, nodeData, distance);

    if(rightCheck != -1) {
        if(rightCheck + 1 == distance) {
            cout << root -> data << endl;
        } else {
            printNodesDistanceToKHelper(root -> left, distance - rightCheck - 2);
        }
        return 1 + rightCheck;
    }
    return -1;
}

//5 2 8 1 3 7 9 -1 -1 -1 4 6 -1 -1 10 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInput();
    printTreeLevelWise(root);

    int nodeData;
    cin >> nodeData;

    int distance;
    cin >> distance;

    printNodesDistanceToK(root, nodeData, distance);

    return 0;
}