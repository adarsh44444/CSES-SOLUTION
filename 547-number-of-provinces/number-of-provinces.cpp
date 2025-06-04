class DisjointSet{
    public: vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findupar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int ulp=findupar(u);
        int vlp=findupar(v);
        if(ulp==vlp) return;
        if(rank[ulp]<rank[vlp]){
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int u=i*n+j;
                int v=j*n+i;
                if(isConnected[i][j]==1){
                    ds.unionbyrank(i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        return cnt;
    }
};