class Solution {
public:
int fun(int index,int buy,int cnt,vector<int>& prices,vector<vector<vector<int>>> &dp){
    int n=prices.size();
    if(index>=n||cnt<=0) return 0;
    int ans=0;
    if(dp[index][buy][cnt]!=-1) return dp[index][buy][cnt];
    if(buy==0){
        ans=max(ans,-prices[index]+fun(index+1,!buy,cnt,prices,dp));
    }
    if(buy==1){
        ans=max(ans,prices[index]+fun(index+1,!buy,cnt-1,prices,dp));
    }
    ans=max(ans,fun(index+1,buy,cnt,prices,dp));
    return dp[index][buy][cnt]=ans;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return fun(0,0,2,prices,dp);
    }
};