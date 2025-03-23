class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n,1e18);
        int mod=(int)(1e9+7);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        vector<pair<long long,long long>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        while(!pq.empty()){
            long long distance=(pq.top().first);
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dist[it.first]>distance+it.second){
                    dist[it.first]=(it.second+distance);
                    pq.push({dist[it.first],it.first});
                    ways[it.first]=ways[node];
                }
                else if(dist[it.first]==it.second+distance){
                ways[it.first]=(ways[node]+ways[it.first])%mod;
            }

        }}
        return ways[n-1]%mod;
    }
};