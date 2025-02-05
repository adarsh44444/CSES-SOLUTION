class Solution {
public:
int solve(int i,int j,vector<vector<int>> &obstacleGrid,int n,int m,vector<vector<int>> &dp){
    if(i==n-1&&j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int moveright=0,movedown=0;
    if(i+1<n&&obstacleGrid[i+1][j]!=1){
        moveright=solve(i+1,j,obstacleGrid,n,m,dp);
    }
    if(j+1<m&&obstacleGrid[i][j+1]!=1){
        movedown=solve(i,j+1,obstacleGrid,n,m,dp);
    }
    return dp[i][j]=moveright+movedown;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        if(obstacleGrid[0][0]==1||obstacleGrid[n-1][m-1]==1) return 0;
        return solve(0,0,obstacleGrid,n,m,dp);
    }
};