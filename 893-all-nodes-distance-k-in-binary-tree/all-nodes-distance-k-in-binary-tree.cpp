/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void solve(unordered_map<TreeNode*,TreeNode*> &markparent,TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr->left) {markparent[curr->left]=curr; q.push(curr->left);}
        if(curr->right) {markparent[curr->right]=curr; q.push(curr->right);}

    }
    return;
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> markparent;
        solve(markparent,root);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        int cnt=0;
        while(!q.empty()){
            if(cnt++==k) break;
            
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left&&!vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right&&!vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(markparent[curr]&&!vis[markparent[curr]]){
                    q.push(markparent[curr]);
                    vis[markparent[curr]]=true;
                }
                
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};