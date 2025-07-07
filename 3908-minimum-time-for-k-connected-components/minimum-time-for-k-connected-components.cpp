class DisjointSet {
public:    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int finduPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = finduPar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ulp_u = finduPar(u);
        int ulp_v = finduPar(v);
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
bool solve(int mid,vector<vector<int>> &edges,int n,int k){
    DisjointSet ds(n);
    for(int i=0;i<edges.size();i++){
        if(edges[i][2]>mid){
            ds.unionbyrank(edges[i][0],edges[i][1]);
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(ds.finduPar(i)==i){
            cnt++;
        }
    }
    return cnt>=k;
}
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low=0,high=1e9;
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,edges,n,k)){ans=mid; high=mid-1;}
            else {low=mid+1;}
        }
        return ans;

    }
};