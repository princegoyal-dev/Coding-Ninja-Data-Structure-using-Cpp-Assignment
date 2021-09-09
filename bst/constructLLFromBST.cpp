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
class Node {
    public :
        T data;
        Node *next;

        Node(T data) {
            this -> data = data;
            next = NULL;
        }
};

Node<int>* constructLLFromBST(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> left == NULL && root -> right == NULL) {
        Node <int> *newNode = new Node <int> (root -> data);
        return newNode;
    }
    Node<int> *leftSubTreeHead =  constructLLFromBST(root -> left);

    Node<int> *rightSubTreeHead = constructLLFromBST(root -> right);

    Node<int> *rootNode = new Node<int>(root -> data);
    cout << "rootNode : " << rootNode -> data << endl;

    if(leftSubTreeHead == NULL) {
        rootNode -> next = rightSubTreeHead;
        return rootNode;
    } else {
        Node <int> *head = leftSubTreeHead;
        while(leftSubTreeHead -> next != NULL) {
            leftSubTreeHead = leftSubTreeHead -> next;
        }
        leftSubTreeHead -> next = rootNode;
        if(rightSubTreeHead != NULL) {
            rootNode -> next = rightSubTreeHead;
        }
        return head;
    }
}

//5 2 8 1 3 7 9 -1 -1 -1 4 6 -1 -1 10 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    printTreeLevelWise(root);

    Node<int> *head = constructLLFromBST(root);
    Node<int> *tempHead = head;
    cout << "before printing the LL : " << endl;
    while(tempHead != NULL) {
        cout << tempHead -> data << " ";
        tempHead = tempHead -> next;
    }
    return 0;
}