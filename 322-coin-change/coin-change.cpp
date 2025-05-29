class Solution {
public:
int dp[13][100001];
int solve(int index,vector<int> &coins,int amount){
    if(index==0){
        if(amount%coins[index]==0) return amount/coins[index];
        else return 1e9;
    }
    if(dp[index][amount]!=-1) return dp[index][amount];
    int pick=0,notpick=0;
    int ans=1e9;
    if(coins[index]<=amount){
        ans=min({ans,1+solve(index-1,coins,amount-coins[index]),1+solve(index,coins,amount-coins[index])});
    }
    ans=min(ans,solve(index-1,coins,amount));
    return dp[index][amount]=ans;
}
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int n=coins.size();
        int ans=solve(n-1,coins,amount);
        if(ans==1e9) return -1;
        return ans;
    }
};