class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &grid,int n,int m,vector<vector<int>> &dp){
        if(i==n-1&&j==m-1) return grid[n-1][m-1];
        int moveright=1e9,movedown=1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i+1<n){
            moveright=grid[i][j]+solve(i+1,j,grid,n,m,dp);
        }
        if(j+1<m){
            movedown=grid[i][j]+solve(i,j+1,grid,n,m,dp);
        }
        return dp[i][j]=min(moveright,movedown);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,grid,n,m,dp);
    }
};