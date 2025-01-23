class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int temp=0;
            if(grid[row][col]==1){
                for(int i=row+1;i<n;i++){
                    if(grid[i][col]==1&&!vis[i][col]){
                        temp++;
                        vis[i][col]=1;
                    }
                }
                for(int i=row-1;i>=0;i--){
                    if(grid[i][col]==1&&!vis[i][col]){
                        temp++;
                        vis[i][col]=1;
                    }
                }
                for(int j=col+1;j<m;j++){
                    if(grid[row][j]==1&&!vis[row][j]){
                        temp++;
                        vis[row][j]=1;
                    }
                }
                for(int j=col-1;j>=0;j--){
                    if(grid[row][j]==1&&!vis[row][j]){
                        temp++;
                        vis[row][j]=1;
                    }
                }
                
            }
            ans+=temp;
        }
        return ans;
    }
};