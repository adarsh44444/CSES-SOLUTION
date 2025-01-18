class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            int steps=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(steps>k) continue;
            for(auto it:adj[node]){
                if(dist[it.first]>cost+it.second&&steps<=k){
                    dist[it.first]=cost+it.second;
                    q.push({steps+1,{it.first,dist[it.first]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];


    
    }
};