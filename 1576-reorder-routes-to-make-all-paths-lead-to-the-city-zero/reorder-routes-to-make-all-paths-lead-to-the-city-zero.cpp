class Solution {
public:
int cnt=0;
void dfs(int node,int parent,unordered_map<int,vector<pair<int,int>>> &adj){
    for(auto it:adj[node]){
        int v=it.first;
        int check=it.second;
        if(v!=parent){
            if(check==1){
                cnt++;
            }
            dfs(v,node,adj);
        }
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }
        dfs(0,-1,adj);
        return cnt;
    }
};