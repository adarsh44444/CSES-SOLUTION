class Solution {
public:
int ans=-1;
void dfs(int node,vector<int>& vis,unordered_map<int,vector<int>>& adj,vector<int> &rank,vector<int> &recursion){
    vis[node]=1;
    recursion[node]=1;
    for(auto it:adj[node]){
        int node_curr=it;
        if(!vis[node_curr]){
            vis[node_curr]=1;
            rank[node_curr]=rank[node]+1;
            dfs(it,vis,adj,rank,recursion);
        }
        else{
            if(vis[it]==1&&recursion[it]==1) ans=max(ans,abs(rank[it]-rank[node])+1);
        }
    }
    recursion[node]=0;
}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> vis(n,0);
        vector<int> rank(n,1);
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            if(edges[i]==-1) continue;
            adj[i].push_back(edges[i]);
        }
        vector<int> recursion(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]&&edges[i]!=-1){
                dfs(i,vis,adj,rank,recursion);
            }
        }
        return ans;

    }
};