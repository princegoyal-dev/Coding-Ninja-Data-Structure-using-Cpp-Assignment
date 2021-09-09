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

void createArr(BinaryTreeNode<int> *root, vector<int> &arr) {
    if(root == NULL) {
        return;
    }
    arr.push_back(root -> data);
    
    createArr(root -> left, arr);
    createArr(root -> right, arr);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    if(root == NULL) {
        return;
    }
    vector<int> dataArr;
    createArr(root, dataArr);
    int i = 0;
    int j = dataArr.size() - 1;
    sort(dataArr.begin(), dataArr.end());
    while(i < j) {
        if(dataArr.at(i) + dataArr.at(j) == sum) {
            cout << dataArr.at(i) << " " << dataArr.at(j) << endl;
            i++;
            j--;
        } else if(dataArr.at(i) + dataArr.at(j) < sum) {
            i++;
        } else j--;
    }
}

// 5 2 8 1 3 7 9 -1 -1 -1 4 6 -1 -1 10 -1 -1 -1 -1 -1 -1 BST
int main() {
    BinaryTreeNode<int> *root = takeInputLevelWise();
    prinTreeLevelWise(root);

    int sum;
    cin >> sum;

    pairSum(root, sum);
    return 0;
}