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
void printZigZag(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }
    queue<BinaryTreeNode<T>*> pendingNodes;
    vector<BinaryTreeNode<T>*> pendingNodesTemp;

    pendingNodes.push(root);
    cout << pendingNodes.front() -> data << endl;
    int i = 1;
    while(true) {
        if(pendingNodes.size() == 0) {
            
            for(int j = 0; j < pendingNodesTemp.size(); j++) {
                pendingNodes.push(pendingNodesTemp[j]);
            }

            if(i % 2 == 0) {
                // cout << "left to right " << endl;
                for(int j = 0; j < pendingNodesTemp.size(); j++) {
                    cout << pendingNodesTemp[j] -> data << " ";
                }
            } else {
                // cout << "right to left" << endl;
                for(int j = pendingNodesTemp.size() - 1; j >= 0; j--) {
                    cout << pendingNodesTemp[j] -> data << " ";
                }
            }
            
            pendingNodesTemp.clear();
            cout << endl;
            i++;
        }
        if(pendingNodes.size() == 0) {
            break;
        }

        BinaryTreeNode<T> *frontNode = pendingNodes.front();
        // cout << "frontNode -> data : " << frontNode -> data << endl;
        pendingNodes.pop();

        if(frontNode -> left != NULL) {
            pendingNodesTemp.push_back(frontNode -> left);
        }
        if(frontNode -> right != NULL) {
            pendingNodesTemp.push_back(frontNode -> right);
        }
        
    }
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    printTreeLevelWise(root);

    printZigZag(root);
    return 0;
}