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
    TreeNode* build(int is,int ie,int ps,int pe,vector<int>& inorder,vector<int>& postorder,map<int,int>& mp){
        if(is>ie||ps>pe) return nullptr;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inroot=mp[postorder[pe]];
        int numsleft=inroot-is;
        root->left=build(is,inroot-1,ps,ps+numsleft-1,inorder,postorder,mp);
        root->right=build(inroot+1,ie,ps+numsleft,pe-1,inorder,postorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder,mp);
    }
};