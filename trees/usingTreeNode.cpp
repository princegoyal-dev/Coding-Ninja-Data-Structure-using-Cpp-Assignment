#include <bits/stdc++.h>
#include "treeNode.cpp"

using namespace std;

int main() {
    TreeNode <int> *root = new TreeNode <int> (10);
    TreeNode <int> *node1 = new TreeNode <int> (20);
    TreeNode <int> *node2 = new TreeNode <int> (30);
    
    root -> children.push_back(node1);
    root -> children.push_back(node2);

    return 0;
}