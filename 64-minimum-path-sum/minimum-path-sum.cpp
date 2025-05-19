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
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,grid,dp);
    }
};