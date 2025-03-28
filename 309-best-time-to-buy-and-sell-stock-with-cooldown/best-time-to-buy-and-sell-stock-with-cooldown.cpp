class Solution {
public:
int fun(int index,vector<int>& prices,int n,int buy,vector<vector<int>> &dp){
    if(index>=n) return 0;
    int pick,notpick,sell;
    if(dp[index][buy]!=-1) return dp[index][buy];
    if(buy==0){
        dp[index][buy]=max(-prices[index]+fun(index+1,prices,n,!buy,dp),fun(index+1,prices,n,buy,dp));
    }
    else{
        dp[index][buy]=max(prices[index]+fun(index+2,prices,n,!buy,dp),fun(index+1,prices,n,buy,dp));
    }
    return dp[index][buy];
    
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return fun(0,prices,n,0,dp);
    }
};