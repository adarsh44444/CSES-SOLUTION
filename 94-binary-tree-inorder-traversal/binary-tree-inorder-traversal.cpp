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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=nullptr){
            TreeNode* pre=curr->left;
            if(pre==nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                while(pre->right!=nullptr){
                    pre=pre->right;
                }
                pre->right=curr;
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=nullptr;
            }
        }
        return ans;
    }
};