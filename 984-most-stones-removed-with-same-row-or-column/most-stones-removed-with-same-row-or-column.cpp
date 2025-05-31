class DisjointSet{
    public: vector<int> rank,parent;
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findupar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int ulp=parent[u];
        int vlp=parent[v];
        if(ulp==vlp) return;
        if(rank[ulp]<rank[vlp]){
            parent[ulp]=vlp;
        }
        else if(rank[ulp]>rank[vlp]){
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
    int removeStones(vector<vector<int>>& stones) {
                int n=stones.size();
                DisjointSet ds(n);
                for(int i=0;i<n-1;i++){
                    int u1=stones[i][0];
                    int v1=stones[i][1];
                        for(int j=i+1;j<n;j++){
                            int u2=stones[j][0];
                            int v2=stones[j][1];
                            if(u1==u2||v1==v2){
                                if(ds.findupar(i)!=ds.findupar(j)){
                                    ds.unionbyrank(i,j);
                                }
                            }
                        }
                }
            int cnt=0;
            for(int i=0;i<=n;i++){
                if(ds.findupar(i)==i){cnt++;}
            }
            return n-cnt+1;
    }
};