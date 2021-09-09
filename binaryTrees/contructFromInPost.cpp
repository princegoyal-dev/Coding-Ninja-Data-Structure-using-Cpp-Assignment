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

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

template <typename T>
BinaryTreeNode<T>* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex)
{
    if (inStrt > inEnd)
        return NULL;
 
    BinaryTreeNode<T>* node = new BinaryTreeNode<T>(post[*pIndex]);
    (*pIndex)--;
 
    if (inStrt == inEnd)
        return node;
 
    int iIndex = search(in, inStrt, inEnd, node->data);
 
    node->right = buildUtil<T>(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil<T>(in, post, inStrt, iIndex - 1, pIndex);
 
    return node;
}
 
template <typename T>
BinaryTreeNode<T>* buildTree(int in[], int post[], int n)
{
    int pIndex = n - 1;
    return buildUtil<T>(in, post, 0, n - 1, &pIndex);
}
 
int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);
 
    BinaryTreeNode<int>* root = buildTree<int>(in, post, n);
 
    // cout << "Preorder of the constructed tree : \n";
    printTreeLevelWise(root);
 
    return 0;
}
// int search(int in[], int start, int end, int value) {
//     int i, index;
//     for(int i = start; i <= end; i++) {
//         if(in[i] == value) {
//             index = i;
//             break;
//         }
//     }
//     return index;
// }

// template <typename T>
// BinaryTreeNode<T>* constructTree(int in[], int post[], int start, int end, int *postIndex) {
    
//     cout << "postIndex : " << *(postIndex) << endl;
//     if(start > end) {
//         return NULL;
//     }
//     BinaryTreeNode<T> *root = new BinaryTreeNode<T> (post[(*postIndex)]);
//     (*postIndex)--;
//     if(start == end) {
//         return root;
//     }
//     cout << "rootData : " << root -> data << endl;
//     int inRootIndex = search(in, start, end, root -> data);
//     cout << "inRootIndex : " << inRootIndex << endl;
//     root -> left = constructTree<T>(in, post, start, inRootIndex - 1, postIndex);
//     root -> right = constructTree<T>(in, post, inRootIndex + 1, end, postIndex);

//     return root;
// }

// int main() {
//     int in[] = {4, 2, 8, 5, 9, 1, 6, 3, 7};
//     int post[] = {4, 8, 9, 5, 2, 6, 7, 3, 1};
//     // BinaryTreeNode<int> *root = takeInput<int>();
//     // printTreeLevelWise(root);

//     int lastIndex = 8;
//     BinaryTreeNode<int> *root = constructTree<int>(in, post, 0, 8, &lastIndex);
//     printTreeLevelWise(root);
//     return 0;
// }