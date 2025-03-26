class Solution {
public:
int solve(int n,vector<int> &dp){
    if(n==0||n<0) return 0;
    int maxi=1e9;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i*i<=n;i++){
        int res=1+solve(n-i*i,dp);
        maxi=min(maxi,res);
    }
    return dp[n]=maxi;
}
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};