/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode* root,vector<int> &ds,int level){
    if(root==nullptr) return;
    if(ds.size()==level) ds.push_back(root->val);
    solve(root->right,ds,level+1);
    solve(root->left,ds,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        solve(root,ds,0);
        return ds;
    }
};