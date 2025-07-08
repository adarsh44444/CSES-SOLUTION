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
TreeNode* helper(TreeNode* root){
    if(root->left==nullptr) return root->right;
    else if(root->right==nullptr) return root->left;
    TreeNode* curr1=root->right;
    TreeNode* curr=root->left;
    TreeNode* copy=curr;
    while(curr->right!=nullptr){
        curr=curr->right;
    }
    curr->right=curr1;
    return copy;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy=root;
        if(root&&root->val==key){
            return helper(root);
        }
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->val>key){
                if(curr->left&&curr->left->val==key){
                    curr->left=helper(curr->left);
                    break;
                }
                else curr=curr->left;
            }
            else{
                if(curr->right&&curr->right->val==key){
                    curr->right=helper(curr->right);
                    break;
                }
                else curr=curr->right;
            }
        }
        return dummy;
    }
};