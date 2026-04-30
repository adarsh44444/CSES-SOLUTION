class Solution {
public:
#define ll long long
ll solve(ll i,ll j,vector<vector<int>>& grid, int k,ll m,ll n,vector<vector<vector<ll>>> &dp){
    if(i>=m||i<0||j>=n||j<0||k<0) return -1e9;
    if(i==m-1&&j==n-1){ 
        return (((grid[i][j]==0?0:1)<=k)?grid[i][j]:-1e9);}
    if(k<0) return -1e9;
    ll right=-1e9,down=-1e9;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if((grid[i][j]==0?0:1)<=k){
        right=grid[i][j]+solve(i+1,j,grid,k-(grid[i][j]==0?0:1),m,n,dp);
        down=grid[i][j]+solve(i,j+1,grid,k-(grid[i][j]==0?0:1),m,n,dp);
    }
    return dp[i][j][k]=max(right,down);
}
    int maxPathScore(vector<vector<int>>& grid, int k) {
        ll m=grid.size(),n=grid[0].size();
        vector<vector<vector<long long>>> dp(
    m, vector<vector<long long>>(
        n, vector<long long>(k+1, -1)
    )
);
        
        int ans=solve(0,0,grid,k,m,n,dp);
        if(ans<0) return -1;
        return ans;
    }
};