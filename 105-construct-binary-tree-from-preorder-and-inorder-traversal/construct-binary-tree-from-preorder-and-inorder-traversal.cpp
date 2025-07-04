class Solution {
public:
    TreeNode* solve(unordered_map<int, int> &mp, int &preindex, vector<int> &preorder, int left, int right) {
        if (left > right) return nullptr;

        int val = preorder[preindex++];
        TreeNode* root = new TreeNode(val);

        int idx = mp[val];

        root->left = solve(mp, preindex, preorder, left, idx - 1);
        root->right = solve(mp, preindex, preorder, idx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int preindex = 0;
        return solve(mp, preindex, preorder, 0, preorder.size() - 1);
    }
};
