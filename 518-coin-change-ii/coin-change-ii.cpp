class Solution {
public:
int dp[301][5001];
    int solve(int index,int amount,vector<int> &coins){
        if(index==0){
            if(amount%coins[index]==0||amount==0) return 1;
            else return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int pick=0;
        int notpick=solve(index-1,amount,coins);
        if(coins[index]<=amount){
            pick=solve(index,amount-coins[index],coins);
        }
        return dp[index][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,amount,coins);
    }
};