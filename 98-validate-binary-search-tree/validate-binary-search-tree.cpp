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
#define ll long long
bool solve(TreeNode* root,ll mini,ll maxi){
    if(root==nullptr) return true;
    if(root->val<=mini||root->val>=maxi) return false;
    return solve(root->left,mini,(ll)root->val)&&solve(root->right,(ll)root->val,maxi);
}
    bool isValidBST(TreeNode* root) {
        ll mini=-1e17,maxi=1e17;
        if(root->left==nullptr&&root->right==nullptr) return true;
        return solve(root,mini,maxi);
    }
};