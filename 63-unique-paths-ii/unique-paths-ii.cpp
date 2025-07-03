class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &o, int n, int m, vector<vector<int>>& dp){
    if(i<0 || j<0 || i>=n || j>=m) return 0;
    if(o[i][j]==1) return 0;
    if(i==n-1 && j==m-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int movedown = solve(i+1, j, o, n, m, dp);
    int moveright = solve(i, j+1, o, n, m, dp);
    return dp[i][j] = movedown + moveright;
}

int uniquePathsWithObstacles(vector<vector<int>>& o) {
    int n = o.size();
    int m = o[0].size();
    if(o[0][0]==1 || o[n-1][m-1]==1) return 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(0, 0, o, n, m, dp);
}

};