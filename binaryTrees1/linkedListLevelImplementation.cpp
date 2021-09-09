#include <bits/stdc++.h>

using namespace std;

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
vector<Node<T>*> convertLL(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        vector<Node<T>*> arrLevel;
        return arrLevel;
    }

    vector<Node<T>*> arrLevel;
    
    queue<BinaryTreeNode<T>*> pendingNodes;
    queue<BinaryTreeNode<T>*> pendingNodesTemp;
    pendingNodes.push(root);

    Node<T> *head = NULL;
    Node<T> *tail = NULL;

    while(true) {

        Node<T> *tempHead = head;
        while(tempHead != NULL) {
            cout << tempHead -> data << " R" << " ";
            tempHead = tempHead -> next;
        }
        cout << endl;

        if(pendingNodes.size() == 0) {
            cout << "pendingNode.size() : 0" << endl;
            arrLevel.push_back(head);
            head = NULL;
            tail = NULL;
            while(pendingNodesTemp.size() != 0) {
                pendingNodes.push(pendingNodesTemp.front()); 
                cout << "pendingNodesTemp.front() : " << pendingNodesTemp.front() -> data << endl;
                pendingNodesTemp.pop();
            }
        }

        if(pendingNodes.size() == 0 && pendingNodesTemp.size() == 0) {
            break;
        }

        BinaryTreeNode<T> *frontNode = pendingNodes.front();
        
        pendingNodes.pop();
        cout << "frontNode -> data : " << frontNode -> data << endl;
        Node<T> *newNode = new Node<T> (frontNode -> data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            cout << "head : frontNode -> data : " << frontNode -> data << endl;
        } else {
            tail -> next = newNode;
            tail = tail -> next;
            // cout << "else tail -> next : " << tail -> next -> data << endl;
        }

        if(frontNode -> left != NULL) {
            pendingNodesTemp.push(frontNode -> left);
        }
        if(frontNode -> right != NULL) {
            pendingNodesTemp.push(frontNode -> right);
        }
    }
    return arrLevel;
}

//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    printTreeLevelWise(root);

    vector<Node<int>*> arrLevel = convertLL(root);

    for(int i = 0; i < arrLevel.size(); i++) {
        Node<int> *tempHead = arrLevel[i];
        while(tempHead != NULL) {
            cout << tempHead -> data << " ";
            tempHead = tempHead -> next;
        }
        cout << endl;
    }
    return 0;
}