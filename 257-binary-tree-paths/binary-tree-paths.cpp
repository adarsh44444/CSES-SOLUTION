class Solution {
public:
    bool isleaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    void solve(TreeNode* root, vector<string>& ans, string temp) {
        if (!root) return;

        // Add current node's value
        if (!temp.empty()) temp += "->";
        temp += to_string(root->val);

        if (isleaf(root)) {
            ans.push_back(temp);
            return;
        }

        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, ans, "");
        return ans;
    }
};
