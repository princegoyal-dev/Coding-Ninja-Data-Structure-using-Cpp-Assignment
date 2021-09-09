#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
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

template <typename T>
BinaryTreeNode<T>* takeInput() {
    T rootData;
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
            BinaryTreeNode<T> *leftChild = new BinaryTreeNode<T>(leftChildData);
            frontNode -> left = leftChild;
            pendingNodes.push(leftChild);
        }
        
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<T> *rightChild = new BinaryTreeNode<T>(rightChildData);
            frontNode -> right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

template <typename T>
void printLevelWise(BinaryTreeNode<T> *root) {
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

vector<int>* returnRootToNodePath(BinaryTreeNode<int> *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> data == data) {
        vector<int> *temp = new vector<int> ();
        temp -> push_back(root -> data);
        return temp;
    }
    vector<int> *leftOutput = returnRootToNodePath(root -> left, data);
    if(leftOutput != NULL) {
        leftOutput -> push_back(root -> data);
        return leftOutput;
    }
    vector<int> *rightOutput = returnRootToNodePath(root -> right, data);
    if(rightOutput != NULL) {
        rightOutput -> push_back(root -> data);
        return rightOutput;
    } else {
        return NULL;
    }
}

// 5 2 8 1 3 7 9 -1 -1 -1 4 6 -1 -1 10 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    printLevelWise(root);

    cout << endl;
    vector<int> *path = returnRootToNodePath(root, 10);
    for(int i = 0; i < path -> size(); i++) {
        cout << path -> at(i) << " ";
    }
    return 0;
}