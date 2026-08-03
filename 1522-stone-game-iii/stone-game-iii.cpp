class Solution {
public:
#define ll long long
ll dp[60000];
ll solve(ll idx,vector<int>& stoneValue,ll n){
    if(idx==n) return 0;
    ll ans=-1e9;
    ll curr=0;
    if(dp[idx]!=-1) return dp[idx];
    for(int j=idx;j<min(idx+3,n);j++){
        curr+=stoneValue[j];
        ans=max(ans,curr-solve(j+1,stoneValue,n));
    }
    return dp[idx]=ans;
}
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        ll n=stoneValue.size();
        ll ans=solve(0,stoneValue,n);
        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
    }
};