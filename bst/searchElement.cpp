#include <bits/stdc++.h>

using namespace std;

class BinaryTreeNode {
    public:
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

BinaryTreeNode* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode *root = new BinaryTreeNode(rootData);

    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode *frontNode = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cin >> leftChildData;

        if(leftChildData != -1) {
            BinaryTreeNode *leftChild = new BinaryTreeNode(leftChildData);
            frontNode -> left = leftChild;
            pendingNodes.push(leftChild);
        }
        
        int rightChildData;
        cin >> rightChildData;

        if(rightChildData != -1) {
            BinaryTreeNode *rightChild = new BinaryTreeNode(rightChildData);
            frontNode -> right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void printTreeLevelWise(BinaryTreeNode *root) {
    if(root == NULL) {
        return;
    }
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode *frontNode = pendingNodes.front();
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

bool searchElement(BinaryTreeNode *root, int value) {
    if(root == NULL) {
        return false;
    }
    if(root -> data == value) {
        return true;
    } else if(root -> data < value) {
        return searchElement(root -> right, value);
    } else  {
        return searchElement(root -> left, value);
    }
}

void printInRange(BinaryTreeNode *root, int lB, int uB) {
    if(root == NULL) {
        return;
    }
    if(root -> data <= uB && root -> data >= lB) {
        cout << root -> data << endl;
    }
    if(root -> data <= lB) {
        return printInRange(root -> right, lB, uB);

    } else if(root -> data >= uB) {
        return printInRange(root -> left, lB, uB);
    } else {
        printInRange(root -> left, lB, uB);
        return printInRange(root -> right, lB, uB);
    }
}
//5 3 12 2 4 10 14 -1 -1 -1 -1 9 11 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode *root = takeInput();
    printTreeLevelWise(root);

    cout << boolalpha << searchElement(root, 9);

    cout << endl;
    printInRange(root, 5, 10);
    return 0;
}