class Solution {
public:
    int dp[5001][2];
    int solve(int index,vector<int> &prices,int n,int buy){
        if(index>=n) return 0;
        int ans=0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy==0){
            ans=max({ans,-prices[index]+solve(index+1,prices,n,1),solve(index+1,prices,n,0)});
        }
        else{
            ans=max({ans,prices[index]+solve(index+2,prices,n,0),solve(index+1,prices,n,1)});
        }
        return dp[index][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,n,0);
    }
};