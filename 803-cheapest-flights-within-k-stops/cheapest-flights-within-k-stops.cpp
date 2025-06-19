class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> vis(n,1e9);
        vis[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                if(stops<=k&&vis[it.first]>cost+it.second){
                    vis[it.first]=cost+it.second;
                    q.push({stops+1,{it.first,vis[it.first]}});
                }
            }
        }
        if(vis[dst]==1e9) return -1;
        else return vis[dst];
    }
};