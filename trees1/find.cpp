#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode {
    public :
    
        T data;
        vector<TreeNode <T> *> children;
        TreeNode(T data) {
            this -> data = data;
        }
        ~TreeNode() {
            for(int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }

};

template <typename T>
TreeNode<T>* takeInput() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    TreeNode<T> *root = new TreeNode<T>(rootData);

    queue <TreeNode<T>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0) {
        TreeNode <T> *front = pendingNodes.front();
        pendingNodes.pop();
        
        int numChild;
        cout << "Enter number of children of " << front -> data << endl;
        cin >> numChild;

        for(int i = 0; i < numChild; i ++) {
            int childData;
            cout << "Enter " << i << "th child data of " << front -> data << endl;
            cin >> childData;

            TreeNode<T> *child = new TreeNode <T> (childData);
            
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
        cout << root -> children[i] -> data << " ";
    }
    cout << endl;
    for(int i = 0; i < root -> children.size(); i++) {
        printTree(root -> children[i]);
    }
}

template <typename T>
bool find(TreeNode <T> *root, T value) {
    bool result = false;
    if(root -> data == value) {
        return true;
    } else {
        for(int i = 0; i < root -> children.size(); i++) {
           result = find(root -> children[i], value);
        }
    }
    return result;
}

template <typename T>
int countNodesGreater(TreeNode <T> *root, T value) {
    if(root == NULL) {
        return 0;
    }
    int num = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        num += countNodesGreater(root -> children[i], value);
    }
    if(root -> data > value) {
        return num + 1;
    } else return num;
}

template <typename T>
class Pair {
    public : 
        TreeNode <T> *node;
        int sum;

        Pair(TreeNode <T> *node, int sum) {
            this -> node = node;
            this -> sum = sum;
        }
};

template <typename T>
Pair<T>* returnMaxSumSubTree(TreeNode <T> *root) {
    if(root == NULL) {
        return 0;
    }
    if(root -> children.size() == 0) {
        Pair<T> *node = new Pair <T>(root, root -> data);
        return node;
    }
    Pair<T> *rootNode = new Pair<T>(root, root -> data);

    for(int i = 0; i < root -> children.size(); i++) {
        rootNode -> sum += root -> children[i] -> data;
    }
    Pair<T> *subTreeNode;
    int count = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        subTreeNode = returnMaxSumSubTree(root -> children[i]);
        // Pair<T> *subTreeNode = new Pair<T> (root -> children[i], root -> children[i] -> data);
        // subTreeNode -> sum += root -> children[i] -> data;
    }
    if(rootNode -> sum < subTreeNode -> sum) {
        return subTreeNode;
    } else {
        return rootNode;
    }
    // int subTreeSum = 0;
    // for(int i = 0; i < root -> children.size(); i++) {
    //     int subTreeData = returnMaxSumSubTree(root -> children[i]);
    //     subTreeSum = root -> children[i] -> data;
    //     for(int j = 0; j < root -> children[i] -> children.size(); j++) {
    //         subTreeSum += root -> children[i] -> children[j] -> data;
    //     }
    //     if(rootSum < subTreeSum) {
    //         ans = subTreeData;
    //         rootSum = subTreeSum;
    //     }
    // }
}

template <typename T>
void maxSumUtil(TreeNode <T>* root, TreeNode <T>** resNode, int* maxsum)
{
    if (root == NULL)
        return;
 
    int currsum = root -> data;

    for (int i = 0; i < root -> children.size(); i++) {
        currsum += root -> children[i] -> data;
        maxSumUtil(root -> children[i], resNode, maxsum);
    }
 
    if (currsum > *maxsum) {
        *resNode = root;
        *maxsum = currsum;
    }
    return;
}
template <typename T>
int maxSum(TreeNode <T>* root)
{
    TreeNode <T> *resNode;
    int maxsum = 0;
    maxSumUtil(root, &resNode, &maxsum);
    return resNode -> data;
}
//5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
//5 3 1 2 3 2 4 10 1 12 2 16 18 0 0 0 2 100 120 1 500 0 1 600 0 0
int main() {
    TreeNode <int> *root = takeInput <int>();
    printTree<int>(root);
    cout << endl;
    cout << boolalpha << find<int>(root, 4);
    cout << endl;
    cout << countNodesGreater(root, 1);
    cout << endl;
    // cout << returnMaxSumSubTree<int>(root) -> node -> data;
    cout << maxSum(root) << endl;
    return 0;
}