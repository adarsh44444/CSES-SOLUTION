class Solution {
public:
int dp[100000][2];
int solve(int index,vector<int>& prices,int buy){
    if(index==prices.size()){
        return 0;
    }
    if(dp[index][buy]!=-1) return dp[index][buy];
    int ans=0;
    if(buy==0){
        ans=max(ans,max(-prices[index]+solve(index+1,prices,1),solve(index+1,prices,0)));
    }
    else{
        ans=max({ans,prices[index]+solve(index+1,prices,0),solve(index+1,prices,1)});
    }
    return dp[index][buy]=ans;
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int n=prices.size();
        dp[n][0]=0;
        dp[n][1]=0;
    
        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                int ans=0;
                if(j==0){
                    ans=max({ans,-prices[i]+dp[i+1][1],dp[i+1][0]});
                }
                else{
                    ans=max({ans,prices[i]+dp[i+1][0],dp[i+1][1]});
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
        /* return solve(0,prices,0); */
    }
};