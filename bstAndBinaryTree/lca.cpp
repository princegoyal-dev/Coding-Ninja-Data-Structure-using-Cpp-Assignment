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

void prinTreeLevelWise(BinaryTreeNode<int> *root) {
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

bool hasData(BinaryTreeNode<int> *root, int data) {
    if(root == NULL) {
        return false;
    }
    // cout << "hasData" << endl;
    // cout << "root -> data : " << root -> data << " " << "sum : " << sum << endl;
    bool result;
    if(data == root -> data) {
        result = true;
    } else {
        result = hasData(root -> left, data);
        if(result == false) {
            result = hasData(root -> right, data);
        }
    }
    return result;
}

int LCA(BinaryTreeNode<int> *root, int data1, int data2) {
    if(root == NULL) {
        return -1;
    }
    if(root -> data == data1) {
        return data1;
    } else if(root -> data == data2) {
        return data2;
    }

    int leftLCA = LCA(root -> left, data1, data2);
    int rightLCA = LCA(root -> right, data1, data2);

    if(leftLCA == -1 && rightLCA == -1) {
        return -1;
    } else if(leftLCA == -1) {
        return rightLCA;
    } else if(rightLCA == -1) {
        return leftLCA;
    } else {
        return root -> data;
    }
}

// 5 2 8 1 3 7 9 -1 -1 -1 4 6 -1 -1 10 -1 -1 -1 -1 -1 -1 BST
int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    prinTreeLevelWise(root);

    int data1, data2;
    cin >> data1 >> data2;

    cout << LCA(root, data1, data2);

    return 0;
}