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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        for(int i=0;i<connections.size();i++){
            if(ds.findupar(connections[i][0])!=ds.findupar(connections[i][1])){
                int u=connections[i][0];
                int v=connections[i][1];
                ds.unionbyrank(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        if(connections.size()>=n-1) return cnt-1;
        return -1;
    }
};