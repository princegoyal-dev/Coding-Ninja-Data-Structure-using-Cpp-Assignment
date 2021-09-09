#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

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

BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

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

void fillData(BinaryTreeNode<int> *root, vector<int> &arr) {
    if(root == NULL) {
        return;
    }
    arr.push_back(root -> data);
    fillData(root -> left, arr);
    fillData(root -> right, arr);
}

void sumReplace(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    vector<int> nodeValues;

    fillData(root, nodeValues);

    sort(nodeValues.begin(), nodeValues.end());
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        int sum = 0;
        bool found = false;
        for(int i = 0; i < nodeValues.size(); i++) {
            if(nodeValues[i] == frontNode -> data || found == true) {
                found = true;
                sum += nodeValues[i];
            }
        }
        frontNode -> data = sum;
        if(frontNode -> left != NULL) {
            pendingNodes.push(frontNode -> left);
        }
        if(frontNode -> right != NULL) {
            pendingNodes.push(frontNode -> right);
        }
    }

}

// 5 2 8 1 3 7 9 -1 -1 -1 4 6 -1 -1 10 -1 -1 -1 -1 -1 -1 BST
int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);

    cout << endl;
    sumReplace(root);
    printTreeLevelWise(root);
    return 0;
}