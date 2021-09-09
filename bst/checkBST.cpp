#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode <T> *left;
        BinaryTreeNode <T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
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

//Problem with this checkBST is : it will check only for the root greater than its left child and right child
//It will not check for the whole left subtree or right subtree;
//Ex. 5 2 8 1 12 7 9 -1 -1 -1 16 6 -1 -1 10 -1 -1 -1 -1 -1 -1
//This is not a subtree although it will print true for this also
template <typename T>
bool checkBST(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return true;
    }
    bool leftCheck = checkBST(root -> left);
    bool rightCheck = checkBST(root -> right);
    bool rootRightCheck = true, rootLeftCheck = true;
    if(root -> left != NULL) {
        if(root -> data > root -> left -> data) {
            rootLeftCheck = true;
        } else rootLeftCheck = false;
    }
    if(root -> right != NULL) {
        if(root -> data <= root -> right -> data) {
            rootRightCheck = true;
        } else rootRightCheck = false;
    }
    return leftCheck && rightCheck && rootLeftCheck && rootRightCheck;
}

template <typename T>
int maximum(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return INT_MIN;
    }
    return max(root -> data, max(maximum(root -> right) , maximum(root -> left)));
}

template <typename T>
int minimum(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return INT_MAX;
    }
    return min(root -> data, min(minimum(root -> left), minimum(root -> right)));
}

template <typename T>
bool checkBST2(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        return true;
    }
    int leftMax = maximum(root -> left);
    int rightMin = minimum(root -> right);

    bool output = (root -> data > leftMax) && (root -> data <= rightMin) && checkBST2(root -> left) && checkBST2(root -> right);
    return output;
}

class isBSTReturn {
    public :
        bool isBST;
        int minimum;
        int maximum;
};

template <typename T>
isBSTReturn checkBST3(BinaryTreeNode<T> *root) {
    if(root == NULL) {
        isBSTReturn output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBST = true;
        return output;
    }

    isBSTReturn leftOutput = checkBST3(root -> left);
    isBSTReturn rightOutput = checkBST3(root -> right);
    // cout << "root -> data : " << root -> data << " " << "leftOutput.isBST : " << leftOutput.isBST << " " << "rightOutput.isBST : " << rightOutput.isBST << " ";
    int maximum = max(root -> data, max(leftOutput.maximum, rightOutput.maximum));
    int minimum = min(root -> data, min(leftOutput.minimum, rightOutput.minimum));
    bool isBSTFinal = (root -> data > leftOutput.maximum) && (root -> data < rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);
    // cout << "maximum : " << maximum << " " << "minimum : " << minimum << " " << "isBSTFinal : " << isBSTFinal << endl;
    isBSTReturn output;
    output.isBST = isBSTFinal;
    output.maximum = maximum;
    output.minimum = minimum; 
    return output;
}

bool checkBST4(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX) {
    if(root == NULL) {
        return true;
    }
    if(root -> data < min || root -> data > max) {
        return false;
    }
    bool isLeftBST = checkBST4(root -> left, min, root -> data - 1);
    bool isRightBST = checkBST4(root -> right, root -> data, max);

    return isLeftBST && isRightBST;
}
// 5 2 8 1 3 7 9 -1 -1 -1 4 6 -1 -1 10 -1 -1 -1 -1 -1 -1 BST
// 5 2 8 1 12 7 9 -1 -1 -1 16 6 -1 -1 10 -1 -1 -1 -1 -1 -1 NOT BSTs
int main() {
    BinaryTreeNode<int> *root = takeInput<int>();
    printLevelWise<int>(root);

    cout << boolalpha << checkBST<int>(root);

    cout << endl;

    cout << boolalpha << checkBST2<int>(root);

    cout << endl;

    isBSTReturn output = checkBST3<int>(root);

    cout << boolalpha << output.isBST;

    cout << endl;

    cout << boolalpha << checkBST4(root);
    return 0;
}