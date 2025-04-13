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
int fun(TreeNode* root,int &cnt){
    if(root==nullptr) return 0;
    int leftheight=fun(root->left,cnt);
    int rightheight=fun(root->right,cnt);
    cnt=max(cnt,leftheight+rightheight);
    return max(leftheight,rightheight)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt=0;
        fun(root,cnt);
        return cnt;
    }
};