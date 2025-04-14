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
void solve(TreeNode* root,string &ans){
    if(root==nullptr) return;
    ans+=to_string(root->val);
    if(root->left!=nullptr||root->right!=nullptr){
        ans+='(';
        solve(root->left,ans);
        ans+=')';
    }
    if(root->right!=nullptr){
        ans+='(';
        solve(root->right,ans);
        ans+=')';
    }
}
    string tree2str(TreeNode* root) {
        string ans="";
        solve(root,ans);
        return ans;
    }
};