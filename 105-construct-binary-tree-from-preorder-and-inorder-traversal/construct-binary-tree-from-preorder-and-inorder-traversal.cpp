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
TreeNode* solve(int left,int right,int &idx,vector<int>&preorder,vector<int>& inorder,unordered_map<int,int> &mp){
    if(left>right) return nullptr;
    int val=preorder[idx++];
    int idxx=mp[val];
    TreeNode* root=new TreeNode(val);
    root->left=solve(left,idxx-1,idx,preorder,inorder,mp);
    root->right=solve(idxx+1,right,idx,preorder,inorder,mp);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int idx=0;
        return solve(0,preorder.size()-1,idx,preorder,inorder,mp);
    }
};