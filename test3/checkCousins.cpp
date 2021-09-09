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
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cin >> leftChildData;

        if(leftChildData != -1) {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int> (leftChildData);
            pendingNodes.push(leftChild);
            frontNode -> left = leftChild;
        }

        int rightChildData;
        cin >> rightChildData;

        if(rightChildData != -1) {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(rightChild);
            frontNode -> right = rightChild;
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int> *root) {
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

int findDepth(BinaryTreeNode<int> *root, int data) {
    if (root == NULL) {
        return -1;
    }
    int distance = -1;
    if( root -> data == data || (distance = findDepth(root -> left, data)) >= 0 || (distance = findDepth(root -> right, data)) >= 0) {
        return 1 + distance;
    }
    return distance;
}

bool isSibling(BinaryTreeNode<int> *root, int node1, int node2) {
    if(root == NULL) {
        return false;
    }
    cout << "root -> data : " << root -> data << endl;
    if(root -> left != NULL && root -> right != NULL) {
        if((root -> left -> data == node1 && root -> right -> data == node2) ||
        (root -> left -> data == node2 && root -> right -> data == node1)) {
            return true;
        }
    }
    return (isSibling(root -> left, node1, node2) || isSibling(root -> right, node1, node2));
}

bool checkCousins(BinaryTreeNode<int> *root, int node1, int node2) {
    if(root == NULL) {
        return false;
    }
    int node1Depth = findDepth(root, node1);
    int node2Depth = findDepth(root, node2);

    cout << "node1Depth : " << node1Depth << " node2Depth : " << node2Depth << endl;

    bool isSiblingReturn = isSibling(root, node1, node2);
    if(node1Depth == node2Depth && !isSiblingReturn) {
        return true;
    } else return false;
    
}

// 5 2 8 1 3 7 9 -1 -1 -1 4 6 -1 -1 10 -1 -1 -1 -1 -1 -1 BST
int main() {
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);

    int node1, node2;
    cin >> node1 >> node2;

    // cout << findDepth(root, 4);
    cout << checkCousins(root, node1, node2);
    return 0;
}