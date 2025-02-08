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
    TreeNode* build(vector<int> &preorder,vector<int> &inorder,int pres,int pree,int ins,int ine,map<int,int> &mp){
        if(pres>pree||ins>ine) return nullptr;
        TreeNode* root=new TreeNode(preorder[pres]);
        int index=mp[preorder[pres]];
        int numsleft=index-ins;
        root->left=build(preorder,inorder,pres+1,pres+numsleft,ins,index-1,mp);
        root->right=build(preorder,inorder,pres+numsleft+1,pree,index+1,ine,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=inorder.size();
        TreeNode* root=build(preorder,inorder,0,n-1,0,n-1,mp);
        return root;
    }
};