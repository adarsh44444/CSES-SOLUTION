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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<pair<int,int>,int>> vec;
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push({{0,0},root});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front().second;
                int dir=q.front().first.first;
                int level=q.front().first.second;
                q.pop();
                vec.push_back({{dir,level},curr->val});
                if(curr->left){
                    q.push({{dir-1,level+1},curr->left});
                }
                if(curr->right){
                    q.push({{dir+1,level+1},curr->right});
                }

            }
        }
        sort(vec.begin(),vec.end());
        int lasst=-1e9;
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<vec.size();i++){
            if(lasst==-1e9){
                temp.push_back(vec[i].second);
                lasst=vec[i].first.first;
            }
            else if(lasst==vec[i].first.first){
                temp.push_back(vec[i].second);
            }
            else{
                ans.push_back(temp);
                while(temp.size()) temp.pop_back();
                lasst=vec[i].first.first;
                temp.push_back(vec[i].second);
            }
        }
        if(!temp.empty()) ans.push_back(temp);
        return ans;
        
    }
};