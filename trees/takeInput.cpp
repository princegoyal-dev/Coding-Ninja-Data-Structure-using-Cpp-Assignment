#include <bits/stdc++.h>
#include "treeNode.cpp"

using namespace std;

template <typename T>
TreeNode<T>* takeInput() {
    T rootData;
    cout << "Enter the root data" << endl;
    cin >> rootData;
    TreeNode<T> *root = new TreeNode<T>(rootData);

    int numChild;
    cout << "Enter the no of children" << endl;
    cin >> numChild;

    for(int i = 0; i < numChild; i++) {
        TreeNode <T> *child = takeInput<T>();
        root -> children.push_back(child);
    } 
    return root;
}

template <typename T>
void printTree(TreeNode<T> *root) {
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
void printLevelWise(TreeNode <T> *root) {
    if(root == NULL) {
        return;
    }
    queue <TreeNode <T> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        TreeNode <T> *front = pendingNodes.front();
        cout << front -> data << " : ";
        pendingNodes.pop();

        for(int i = 0; i < front -> children.size(); i++) {
            cout << front -> children[i] -> data << ", ";
            pendingNodes.push(front -> children[i]);
        }
        cout << endl;
    }
}

template <typename T>
TreeNode<T>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;

    TreeNode<T> *root = new TreeNode<T>(rootData);

    queue<TreeNode<T>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cin >> numChild;
        for(int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;

            TreeNode<T>* child = new TreeNode<T>(childData);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int countChild(TreeNode <int> *root) {
    int ans = 1;
    for(int i = 0; i < root -> children.size(); i++) {
        ans += countChild(root -> children[i]);
    }
    return ans;
}

int getHeight(TreeNode <int> *root) {
    if(root == NULL) {
        return 0;
    }
    int maxHeight = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        int height = getHeight(root -> children[i]);
        if(maxHeight < height) {
            maxHeight = height;
        }
    }
    return maxHeight + 1;
}   

void getKthNodes(TreeNode <int> *root, int depth) {
    if(depth == 0) {
        cout << root -> data << " ";
    }
    for(int i = 0; i < root -> children.size(); i++) {
        getKthNodes(root -> children[i], depth - 1);
    }
}

int countLeaf(TreeNode <int> *root) {
    if(root == NULL) {
        return 0;
    }
    if(root -> children.size() == 0) {
        return 1;
    }
    int num = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        num += countLeaf(root -> children[i]);
    }
    return num;
}

void preOrder(TreeNode <int> *root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " : ";
    for(int i = 0; i < root -> children.size(); i++) {
        cout << root -> children[i] -> data << ", ";
    }
    cout << endl;
    for(int i = 0; i < root -> children.size(); i++) {
        preOrder(root -> children[i]);
    }
}

void postOrder(TreeNode <int> *root) {
    if(root == NULL) {
        return;
    }
    for(int i = 0; i < root -> children.size(); i++) {
        postOrder(root -> children[i]);
    }
    for(int i = 0; i < root -> children.size(); i++) {
        cout << root -> children[i] -> data << " ";
    }
    cout << " : " << root -> data;
    cout << endl;

}
//1 3 2 3 4 2 5 6 3 7 8 9 5 10 11 12 13 14 0 0 0 0 0 0 0 0 0 0
int main() {
    TreeNode <int> *root = takeInputLevelWise<int>();
    printTree(root);
    cout << endl;
    printLevelWise(root);
    cout << endl;
    cout << "No of Nodes : " << countChild(root);
    cout << endl;
    cout << "Max height : " << getHeight(root);
    cout << endl;
    getKthNodes(root, 2);
    cout << endl;
    cout << "count leaf : " << countLeaf(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    return 0;
}