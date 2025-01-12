class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& temp) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, temp);
        temp.push_back(root->val);
        inorderTraversal(root->right, temp);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> temp;
        inorderTraversal(root, temp); // Get sorted in-order traversal
        vector<vector<int>> ans;

        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            int it = lower_bound(temp.begin(), temp.end(), query) - temp.begin();

            if (it < temp.size() && temp[it] == query) {
                // Exact match found
                ans.push_back({temp[it], temp[it]});
            } else {
                // Handle bounds
                int lower = (it > 0) ? temp[it - 1] : -1;
                int upper = (it < temp.size()) ? temp[it] : -1;
                ans.push_back({lower, upper});
            }
        }
        return ans;
    }
};
