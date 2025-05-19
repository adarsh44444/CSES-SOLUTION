class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n||j==m||i==-1||j==-1) return 1e9;
        if(i==n-1&&j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        int val=grid[i][j];
        ans=min({val+solve(i+1,j,grid,dp),val+solve(i,j+1,grid,dp)});
        return dp[i][j]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        // dynamic programming solution will work not the greedy one
        // memoization stuff
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // top down
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) {dp[i][j]=grid[0][0];continue;}
                if(i==0) {dp[i][j]=(grid[i][j]+dp[i][j-1]); continue;}
                if(j==0) {dp[i][j]=grid[i][j]+dp[i-1][j]; continue;}
                dp[i][j]=min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};