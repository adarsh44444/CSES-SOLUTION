class Solution {
public:
    void dfs(int source,int dest,vector<vector<int>>& graph,vector<vector<int>> &ans,vector<int> &temp){
        temp.push_back(source);
        if(source==dest){
            ans.push_back(temp);
        }
        else{
        for(auto it:graph[source]){
            dfs(it,dest,graph,ans,temp);
        }}
        temp.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=graph.size();
        dfs(0,n-1,graph,ans,temp);
        return ans;
    }
};