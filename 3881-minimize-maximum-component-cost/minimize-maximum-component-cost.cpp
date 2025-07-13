class DisjointSet{
public: vector<int> rank,parent;
DisjointSet(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++) parent[i]=i;
}
int findupar(int node){
    if(node==parent[node]) return node;
    return parent[node]=findupar(parent[node]);
}
void unionbyrank(int u,int v){
    int ulp=findupar(u);
    int vlp=findupar(v);
    if(ulp==vlp) return;
    else if(rank[ulp]<rank[vlp]){
        parent[ulp]=vlp;
    }
    else if(rank[vlp]<rank[ulp]){
        parent[vlp]=ulp;
    }
    else{
        parent[ulp]=vlp;
        rank[vlp]++;
    }
}
};
class Solution {
public:
bool solve(int mid,int n,vector<vector<int>> &edges,int k){
    DisjointSet ds(n);
    for(int i=0;i<edges.size();i++){
        if(edges[i][2]<=mid){
            ds.unionbyrank(edges[i][0],edges[i][1]);
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(ds.findupar(i)==i) cnt++;
    }
    return cnt<=k;
}
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int low=0;
        int high=0;
        for(auto it:edges){
            high=max(high,it[2]);
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,n,edges,k)) {ans=mid; high=mid-1;}
            else low=mid+1;
        }
        return ans;
    }
};