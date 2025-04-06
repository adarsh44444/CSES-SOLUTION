class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1,-1);
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==vis[node]) return false;
                else{
                    if(vis[it]==-1){
                        q.push(it);
                        vis[it]=!vis[node];
                    }
                }
            }
        }}}
/*         for(int i=1;i<=n;i++) if(vis[i]==-1) return false; */
        return true;
    }
};