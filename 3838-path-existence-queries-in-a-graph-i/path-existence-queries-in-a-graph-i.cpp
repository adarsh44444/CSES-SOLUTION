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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        int i=0;int j=0;
        while(j<nums.size()){
            if((nums[j]-nums[i])<=maxDiff){
                ds.unionbyrank(i,j);
                j++;
            }
            else{
                i++;
                }
            }
            vector<bool> ans;
            for(auto it:queries){
                int u=it[0];
                int v=it[1];
                if(ds.findupar(u)==ds.findupar(v)){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
            return ans;
        }
};