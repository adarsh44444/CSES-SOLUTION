#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int, int> inorderIndex;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int idx = inorderIndex[rootVal];

        // Build right subtree first
        root->right = build(inorder, postorder, idx + 1, right);
        root->left = build(inorder, postorder, left, idx - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};
