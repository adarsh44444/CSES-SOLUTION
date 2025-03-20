class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);
        vector<int> cost(n,-1);
        set<pair<int,int>> st;
        for(auto it:edges){
            st.insert({it[0],it[1]});
            ds.unionByRank(it[0],it[1]);
        }
        for(auto it:edges){
            int root=ds.findUPar(it[0]);
            cost[root]&=it[2];
        }
        vector<int> ans;
        for(auto it:query){
            if(ds.findUPar(it[0])!=ds.findUPar(it[1])){
                ans.push_back(-1);
            }
            else{
                ans.push_back(cost[ds.findUPar(it[0])]);
            }
        }
        return ans;
    }
};