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
    int sum;
    void solve(TreeNode* root){
        if(root->left!=nullptr){
            if(root->left->left==nullptr&&root->left->right==nullptr) sum+=root->left->val;
            solve(root->left);
        }
        if(root->right!=nullptr){
            solve(root->right);
        }
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum=0;
        solve(root);
        return sum;
    }
};