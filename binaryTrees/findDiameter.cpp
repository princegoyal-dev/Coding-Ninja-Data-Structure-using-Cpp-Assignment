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
};

template <typename T>
BinaryTreeNode<T>* takeInput() {
    int rootData;
    cin >> rootData;

    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<T> *root = new BinaryTreeNode<T> (rootData);

    root -> left = takeInput<T>();
    root -> right = takeInput<T>();

    return root;
}

template <typename T> 
void printTree(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " : ";
    if(root -> left != NULL) {
        cout << "L" << root -> left -> data << " ";
    }
    if(root -> right != NULL) {
        cout << "R" << root -> right -> data;
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);
}

template <typename T>
BinaryTreeNode<T>* takeInputBetter() {
    T rootData;
    cin >> rootData;

    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData);

    queue<BinaryTreeNode<T>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        BinaryTreeNode<T> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cin >> leftChildData;

        if(leftChildData != -1) {
            BinaryTreeNode<T> *leftChild = new BinaryTreeNode<T>(leftChildData);
            pendingNodes.push(leftChild);
            frontNode -> left = leftChild;
        }
        
        int rightChildData;
        cin >> rightChildData;

        if(rightChildData != -1) {
            BinaryTreeNode<T> *rightChild = new BinaryTreeNode<T>(rightChildData);
            pendingNodes.push(rightChild);
            frontNode -> right = rightChild;
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

// template <typename T>
// int height(BinaryTreeNode<T> *root) {
//     if(root == NULL) {
//         return 0;
//     }
//     return 1 + max(height(root -> left), height(root -> right));
// }

// template <typename T>
// int getDiameter(BinaryTreeNode<T> *root) {
//     if(root == NULL) {
//         return 0;
//     }
//     int option1 = height(root -> left) + height(root -> right);
//     int option2 = getDiameter(root -> left);
//     int option3 = getDiameter(root -> right);
//     return max(option1, max(option2, option3));
// }

template <typename T>
pair<int, int> getDiameterHelper(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        pair<int, int> diameter;
        diameter.first = 0;
        diameter.second = 0;
        return diameter;
    }
    pair<int, int> leftAns = getDiameterHelper(root -> left);
    pair<int, int> rightAns = getDiameterHelper(root -> right);
    int leftDiameter = leftAns.second;
    int rightDiameter = rightAns.second;
    int leftHeight = leftAns.first;
    int rightHeight = rightAns.first;

    int height = 1 + max(leftHeight, rightHeight);
    int diameter = max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));

    pair<int, int> diameterObject;
    diameterObject.first = height;
    diameterObject.second = diameter;

    return diameterObject;
}

template <typename T>
int getDiameter(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return 0;
    }
    pair<int, int> result;
    result = getDiameterHelper(root);
    return result.second;
}

//simple takeInput ie root left right 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
//better takeInput ie levelOrder Wise 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
int main() {
    BinaryTreeNode<int> *root = takeInputBetter<int>();
    printTreeLevelWise(root);

    cout << endl;

    int diameter = getDiameter<int>(root);
    cout << diameter;
    return 0;
}