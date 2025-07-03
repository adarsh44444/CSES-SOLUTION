class Solution {
public:
int dp[201][201];
int solve(int i,int j,vector<vector<int>> &t,int n,int m){
    if(i==n-1&&j<m&&j>=0){
        return t[i][j];
    }
    if(i>=n||j>=m) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int movedown=0,moveright=0;
    movedown=t[i][j]+solve(i+1,j+1,t,n,m);
    moveright=t[i][j]+solve(i+1,j,t,n,m);
    return dp[i][j]=min(movedown,moveright);
}
    int minimumTotal(vector<vector<int>>& t) {
        memset(dp,-1,sizeof(dp));
        int n=t.size();
        int m=t[n-1].size();
        return solve(0,0,t,n,m);
    }
};