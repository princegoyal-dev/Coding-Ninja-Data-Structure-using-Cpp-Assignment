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
class BSTClass {
    private:
        BinaryTreeNode<T> *root;

        BinaryTreeNode<T>* insert(BinaryTreeNode<T> *root, T data) {
            if(root == NULL) {
                BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(data);
                return newNode;
            }
            if(data < root -> data) {
                root -> left = insert(root -> left, data);
            }
            if(data >= root -> data) {
                root -> right = insert(root -> right, data);
            }
            return root;
        }

        bool hasData(BinaryTreeNode<T> *root, T data) {
            if(root == NULL) {
                return false;
            }
            if(root -> data == data) {
                return true;
            } else if(data < root -> data) {
                return hasData(root -> left, data);
            } else {
                return hasData(root -> right, data);
            }
        }

        BinaryTreeNode<T>* deleteData(BinaryTreeNode<T> *root, T data) {
            if(root == NULL) {
                return NULL;
            }
            if(data < root -> data) {
                root -> left = deleteData(root -> left, data);
                return root;
            }
            if(data > root -> data) {
                root -> right = deleteData(root -> right, data);
                return root;
            } else {
                if(root -> left == NULL && root -> right == NULL) {
                    delete root;
                    return NULL;
                }
                if(root -> left == NULL) {
                    BinaryTreeNode<T> *temp = root -> right;
                    root -> right = NULL;
                    delete root;
                    return temp;
                }
                if(root -> right == NULL) {
                    BinaryTreeNode<T> *temp = root -> left;
                    root -> left = NULL;
                    delete root;
                    return temp;
                } else {
                    BinaryTreeNode<T> *minNode = root -> right;
                    while(minNode -> left != NULL) {
                        minNode = minNode -> left;
                    }
                    int rightMin = minNode -> data;
                    root -> data = rightMin;
                    root -> right = deleteData(rightMin);
                    return root;
                }
            }
        }

    public:
        BSTClass() {
            root = NULL;
        }
        void insert(T data) {
            this -> root = insert(root, data);
        }
        bool hasData(T data) {
            return hasData(root, data);
        }
        void deleteData(T data) {
            this -> root = deleteData(root, data);
        }
};

int main() {
    
    return 0;
}