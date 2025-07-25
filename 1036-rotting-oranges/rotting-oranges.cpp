class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    pq.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int ans=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!pq.empty()){
            int time=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            ans=max(ans,time);
            pq.pop();
            for(int i=0;i<4;i++){
                int adjrow=row+dx[i];
                int adjcol=col+dy[i];
                if(adjrow>=0&&adjrow<n&&adjcol>=0&&adjcol<m&&grid[adjrow][adjcol]==1&&vis[adjrow][adjcol]==0){
                    pq.push({time+1,{adjrow,adjcol}});
                    vis[adjrow][adjcol]=1;
                }
            }
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]==1) flag=false;
            }
        }
        if(!flag) return -1;
        return ans;
    }
};