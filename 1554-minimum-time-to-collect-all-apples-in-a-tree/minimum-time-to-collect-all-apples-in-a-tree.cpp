class Solution {
public:
    int solve(int node,int parent,unordered_map<int,vector<int>>&adj,vector<bool> &hasApple){
        int time=0;
        for(auto it:adj[node]){
            if(it==parent) continue;
            int timefrom=solve(it,node,adj,hasApple);
            if(timefrom>0||hasApple[it]){
                time+=timefrom+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return solve(0,-1,adj,hasApple);
    }
};