class DisjointSet{
    public:
    vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,1);
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
            rank[vlp]+=rank[ulp];
        }
        else{
            parent[vlp]=ulp;
            rank[ulp]+=rank[vlp];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int u=m*i+j;
                if(grid[i][j]==1){
                if(i+1<n&&grid[i+1][j]==1){
                    int v=m*(i+1)+j;
                    if(ds.findupar(u)!=ds.findupar(v)){
                        ds.unionbyrank(u,v);
                    }
                }
                if(i-1>=0&&grid[i-1][j]==1){
                    int v=m*(i-1)+j;
                    if(ds.findupar(u)!=ds.findupar(v)){
                        ds.unionbyrank(u,v);
                    }
                }
                if(j+1<m&&grid[i][j+1]==1){
                    int v=m*i+j+1;
                    if(ds.findupar(u)!=ds.findupar(v)){
                        ds.unionbyrank(u,v);
                    }
                }
                if(j-1>=0&&grid[i][j-1]==1){
                    int v=m*i+j-1;
                    if(ds.findupar(u)!=ds.findupar(v)){
                        ds.unionbyrank(u,v);
                    }
                }
            }
        }
    }
    int ans1=*max_element(ds.rank.begin(),ds.rank.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int u,v,w,x;
            int ans=0;
            if(grid[i][j]==0){
                set<int> st;
                if(i+1<n&&grid[i+1][j]==1){
                    st.insert(ds.findupar(m*(i+1)+j));
                }
                if(i-1>=0&&grid[i-1][j]==1){
                    st.insert(ds.findupar(m*(i-1)+j));
                }
                if(j+1<m&&grid[i][j+1]==1){
                    st.insert(ds.findupar(m*(i)+j+1));
                }
                if(j-1>=0&&grid[i][j-1]==1){
                    st.insert(ds.findupar(m*i+(j-1)));
                }
                for(auto it:st){
                    ans+=ds.rank[it];
                }
                ans1=max(ans+1,ans1);
            }
            }
        }
        return ans1;
    }
    
};