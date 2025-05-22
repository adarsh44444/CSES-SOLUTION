class Solution {
public:
int dfs(int node,int k,int sum,int n,vector<vector<int>> &edges,int t,vector<vector<pair<int,int>>>&adj
,vector<vector<unordered_map<int,int>>> &mp){
    if(k==0&&sum<t) return sum;
    if(k==0&&sum>=t) return -1;
    if(mp[node][k].count(sum)) return mp[node][k][sum];
    int maxi=-1;
    for(auto it:adj[node]){
        int neighbour=it.first;
        int cost=it.second;
        if(cost+sum<t){
            maxi=max(maxi,dfs(neighbour,k-1,sum+cost,n,edges,t,adj,mp));
        }
    }
    return mp[node][k][sum]=maxi;
}
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<unordered_map<int,int>>> mp(n,vector<unordered_map<int,int>>(k+1));
        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,dfs(i,k,0,n,edges,t,adj,mp));
        }
        return ans;
    }
};