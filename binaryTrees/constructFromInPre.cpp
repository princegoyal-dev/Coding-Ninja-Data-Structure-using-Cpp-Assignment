// #include <bits/stdc++.h>

// using namespace std;

// template <typename T>
// class BinaryTreeNode {
//     public :
//         T data;
//         BinaryTreeNode<T> *left;
//         BinaryTreeNode<T> *right;

//         BinaryTreeNode(T data) {
//             this -> data = data;
//             left = NULL;
//             right = NULL;
//         }
// };

// template <typename T>
// BinaryTreeNode<T>* takeInput() {
//     T rootData;
//     cin >> rootData;
//     if(rootData == -1) {
//         return NULL;
//     }

//     BinaryTreeNode<T> *root = new BinaryTreeNode<T> (rootData);

//     queue<BinaryTreeNode<T>*> pendingNodes;
//     pendingNodes.push(root);

//     while(pendingNodes.size() != 0) {
//         BinaryTreeNode<T> *frontNode = pendingNodes.front();
//         pendingNodes.pop();

//         int leftChildData;
//         cin >> leftChildData;
//         if(leftChildData != -1) {
//             BinaryTreeNode<T> *leftChild = new BinaryTreeNode<T> (leftChildData);
//             frontNode -> left = leftChild;
//             pendingNodes.push(leftChild);
//         }
//         int rightChildData;
//         cin >> rightChildData;
//         if(rightChildData != -1) {
//             BinaryTreeNode<T> *rightChild = new BinaryTreeNode<T> (rightChildData);
//             frontNode -> right = rightChild;
//             pendingNodes.push(rightChild);
//         }
//     }
//     return root;
// }

// template <typename T>
// void printTreeLevelWise(BinaryTreeNode<T> *root) {
//     if(root == NULL) {
//         return;
//     }
//     queue<BinaryTreeNode<T>*> pendingNodes;
//     pendingNodes.push(root);
    
//     while(pendingNodes.size() != 0) {
//         BinaryTreeNode<T> *frontNode = pendingNodes.front();
//         pendingNodes.pop();

//         cout << frontNode -> data << " : ";
//         if(frontNode -> left != NULL) {
//             cout << "L" << frontNode -> left -> data << " ";
//             pendingNodes.push(frontNode -> left);
//         }
//         if(frontNode -> right != NULL) {
//             cout << "R" << frontNode -> right -> data;
//             pendingNodes.push(frontNode -> right);
//         }
//         cout << endl;
//     }
// }

// // template <typename T>
// // BinaryTreeNode<T>* buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE) {
// //     if(inS > inE) {
// //         return NULL;
// //     }
// //     int rootData = pre[preS];
// //     int rootIndex = -1;
// //     for(int i = inS; i <= inE; i++) {
// //         if(in[i] == rootData) {
// //             rootIndex = i;
// //             break;
// //         }
// //     }
// //     int leftInStart = inS;
// //     int leftInEnd = rootIndex - 1;
// //     int leftPreStart = preS + 1;
// //     int leftPreEnd = leftInEnd - leftInStart + leftPreStart;
// //     int rightPreStart = leftPreEnd + 1;
// //     int rightPreEnd = preE;
// //     int rightInStart = rootIndex + 1;
// //     int rightInEnd = inE;

// //     cout << "in function" << endl;
// //     BinaryTreeNode<T> *root = new BinaryTreeNode<T> (rootData);
// //     root -> left = buildTreeHelper<T>(in, pre, leftInStart, leftInEnd, leftPreStart, leftPreEnd);
// //     root -> right = buildTreeHelper<T>(in, pre, rightInStart, rightInEnd, rightPreStart, rightPreEnd);
// //     return root;
// // }

// template <typename T>
// BinaryTreeNode<T>* buildTree(int *in, int *pre, int start, int end) {
//     static int preIndex = 0;
//     if(start > end) {
//         return NULL;
//     }
//     BinaryTreeNode<T> *root = new BinaryTreeNode<T>(pre[preIndex++]);
//     if(start == end) {
//         return root;
//     }
//     int rootIndex = -1;
//     for(int i = start; i <= end; i++) {
//         if(in[i] == root -> data) {
//             rootIndex = i;
//             break;
//         }
//     }

//     root -> left = buildTree<T>(in, pre, start, rootIndex - 1);
//     root -> right = buildTree<T>(in, pre, rootIndex + 1, end);

//     return root;
//     // return buildTreeHelper<T>(in, pre, 0, size - 1 , 0, size - 1);
// }

// //1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
// //pre 1 3 7 6 2 5 9 8 4
// //in 7 3 6 1 9 5 8 2 4
// int main() {
//     int pre[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
//     int in[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
//     int size = sizeof(pre) / sizeof(pre[0]);

//     // BinaryTreeNode<int> *root = takeInput<int>();
//     // printTreeLevelWise(root);
//     cout << size;

//     BinaryTreeNode<int> *root = buildTree<int>(in, pre, 0, size - 1);
//     printTreeLevelWise(root);
//     return 0;
// }

/* C++ program to construct tree using
inorder and preorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
template <typename T>
class node
{
    public:
    T data;
    node<T>* left;
    node<T>* right;
};

/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value);
node* newNode(char data);

/* Recursive function to construct binary
of size len from Inorder traversal in[]
and Preorder traversal pre[]. Initial values
of inStrt and inEnd should be 0 and len -1.
The function doesn't do any error checking
for cases where inorder and preorder do not
form a tree */
node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder
    traversal using preIndex
    and increment preIndex */
    node* tNode = newNode(pre[preIndex++]);

    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;

    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(char data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

/* This funtcion is here just to test buildTree() */
void printInorder(node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout<<node->data<<" ";

    /* now recur on right child */
    printInorder(node->right);
}

/* Driver code */
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    node* root = buildTree(in, pre, 0, len - 1);

    /* Let us test the built tree by
    printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}

// This is code is contributed by rathbhupendra
