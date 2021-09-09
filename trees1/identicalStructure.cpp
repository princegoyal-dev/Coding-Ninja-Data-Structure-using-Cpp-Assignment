#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode {
    public : 
        T data;
        vector <TreeNode <T> *> children;

        TreeNode (T data) {
            this -> data = data;
        }
};

template <typename T>
TreeNode <T>* takeInput() {
    int rootData;
    cin >> rootData;

    TreeNode<T> *root = new TreeNode<T>(rootData);

    queue <TreeNode <T> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        TreeNode <T> *front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cin >> numChild;

        for(int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;

            TreeNode <T> *child = new TreeNode<T> (childData);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

template <typename T>
void printTree(TreeNode <T> *root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " : ";
    for(int i = 0; i < root -> children.size(); i++) {
        cout << root -> children[i] -> data << ", ";
    }
    cout << endl;
    for(int i = 0; i < root -> children.size(); i++) {
        printTree(root -> children[i]);
    }
}

template <typename T>
bool checkIdentical(TreeNode <T> *root1, TreeNode <T> *root2) {
    if(root1 == NULL || root2 == NULL) {
        return false;
    }
    if(root1 -> data != root2 -> data) {
        return false;
    }
    bool result = true;
    for(int i = 0; i < root1 -> children.size(); i++) {
        result = checkIdentical(root1 -> children[i], root2 -> children[i]);
    }
    return result;
}

//code for next greater find
template <typename T>
void findNextGreaterHelper(TreeNode <T> *root, T value, T *maxValue, T *greaterValue) {

    for(int i = 0; i < root -> children.size(); i++) {
        findNextGreaterHelper(root -> children[i], value, maxValue, greaterValue);
    }

    if(root -> data > value) {
        *maxValue = root -> data;
        if(*greaterValue == value) {
            *greaterValue = *maxValue;
        }
        if(*greaterValue > *maxValue) {
            *greaterValue = *maxValue;
        }
    }
}

template <typename T>
T* findNextGreater(TreeNode <T> *root, T value) {
    T maxValue = 0;
    T greaterValue = value;
    findNextGreaterHelper(root, value, &maxValue, &greaterValue);

    if(greaterValue == value) {
        return NULL;
    }
    int *greaterValuePointer = new int(greaterValue);
    return greaterValuePointer;
}
//code end for next greater find

// template <typename T>
// T* findLargest(TreeNode <T> *root) {
//     if(root == NULL) {
//         return NULL;
//     }
//     T *max = new int(root -> data);
//     T *nextMax = new int(root -> data);
//     for(int i = 0; i < root -> children.size(); i++) {
//         nextMax = findLargest(root -> children[i]);
//     }
//     if(*max < *nextMax) return nextMax;
//     else return max;
// }

// template <typename T>
// T* findSecondLargest(TreeNode <T> *root,T *secondMaxElement, T **maxElementData) {
//     if(root == NULL) {
//         return NULL;
//     }
//     if(root -> data < **maxElementData) {
//         secondMaxElement = new int(root -> data);
//     }
//     for(int i = 0; i < root -> children.size(); i++) {
//         secondMaxElement = findSecondLargest(root -> children[i], secondMaxElement, maxElementData);
//     }
//     return secondMaxElement;
// }

template <typename T>
void findSecondLargestHelper(TreeNode <T> *root, TreeNode<T> **first, TreeNode<T> **second) {
    if(root == NULL) {
        return;
    }
    if(!(*first)) {
        *first = root;
    } else if(root -> data > (*first) -> data) {
        *second = *first;
        *first = root;
    } else if(!(*second)) {
        *second = root;
    } else if(root -> data < (*first) -> data && root -> data > (*second) -> data) {
        *second = root;
    }
    for(int i = 0; i < root -> children.size(); i++) {
        findSecondLargestHelper<T>(root -> children[i], first, second);
    }
}

template <typename T>
TreeNode<T>* findSecondLargest(TreeNode <T> *root) {
    if(root == NULL) {
        return NULL;
    }
    TreeNode <T> *first = NULL;
    TreeNode <T> *second = NULL;

    findSecondLargestHelper<T>(root, &first, &second);

    return second;
}

template <typename T>
int getHeight(TreeNode <T> *root) {
    if(root == NULL) {
        return 0;
    }
    int depth = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        int smallHeight = getHeight(root -> children[i]);
        if(depth < smallHeight) {
            depth = smallHeight;
        }
    }
    return depth + 1;
}

template <typename T>
void replaceDataHeight(TreeNode <T> *root) {
    if(root == NULL) {
        return;
    }
    int rootHeight = getHeight(root);
    root -> data = rootHeight;
    for(int i = 0; i < root -> children.size(); i++) {
        int height = getHeight(root -> children[i]);
        root -> children[i] -> data = (height - 1);
    }
    for(int i = 0; i < root -> children.size(); i++) {
        replaceDataHeight(root -> children[i]);
    }
}

//5 3 1 2 3 1 4 2 4 5 1 6 0 0 0 0
//5 3 1 2 3 2 4 10 1 12 2 16 18 0 0 0 2 100 120 1 500 0 1 600 0 0
int main() {
    TreeNode <int> *root = takeInput<int>();
    printTree<int>(root);

    // check identical
    // TreeNode <int> *root1 = takeInput<int>();
    // printTree<int>(root1);
    // TreeNode <int> *root2 = takeInput<int> ();
    // printTree<int>(root2);
    // cout << endl;
    // cout << boolalpha << checkIdentical(root1, root2);

    // get next Greater
    // cout << endl;
    // int value = 10;
    // int *result = findNextGreater<int>(root, value);
    // if(result != NULL) {
    //     cout << *result << endl;
    // } else cout << "NULL" << endl;
    // delete result;
    
    // find second max
    // TreeNode<int> *secondMaxNode = findSecondLargest <int>(root);
    // cout << secondMaxNode -> data;
    
    //replace data with height
    replaceDataHeight(root);
    printTree(root);
    
    return 0;
}