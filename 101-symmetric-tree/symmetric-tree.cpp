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
bool solve(TreeNode* right,TreeNode* left){
    if(right==nullptr||left==nullptr){
        return right==left;
    }
    if(right->val!=left->val) return false;
    return solve(right->left,left->right)&&solve(right->right,left->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return false;
        return solve(root->right,root->left);
    }
};