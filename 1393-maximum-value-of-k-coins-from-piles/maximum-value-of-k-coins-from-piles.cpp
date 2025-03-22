class Solution {
public:
int solve(int index,vector<vector<int>>& piles, int k,vector<vector<int>> &dp){
    int n=piles.size();
    if(k==0||index==n){
        return 0;
    }
    if(dp[index][k]!=-1) return dp[index][k];
    int notpick=solve(index+1,piles,k,dp),curr=0;
    for(int i=0;i<piles[index].size()&&i<k;i++){
        curr+=piles[index][i];
        notpick=max(notpick,solve(index+1,piles,k-i-1,dp)+curr);
    }
    return dp[index][k]=notpick;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,piles,k,dp);
    }
};