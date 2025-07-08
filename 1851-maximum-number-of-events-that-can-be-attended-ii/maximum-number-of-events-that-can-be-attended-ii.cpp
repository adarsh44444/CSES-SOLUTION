class Solution {
public:
#define ll long long
ll solve(ll idx,vector<vector<int>> &events,ll k,vector<vector<int>> &dp){
    if(idx>=events.size()||k==0) return 0;
    if(dp[idx][k]!=-1) return dp[idx][k];
    ll start=events[idx][0];
    ll end=events[idx][1];
    ll val=events[idx][2];
    ll notpick=solve(idx+1,events,k,dp);
    ll pick=val;
    ll low=idx,high=events.size()-1;
    ll n=events.size();
    ll ans=n;
    while(low<=high){
        ll mid=(low+high)/2;
        if(events[mid][0]>end){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    if(ans<n){
        pick+=solve(ans,events,k-1,dp);
    }
    return dp[idx][k]=max(pick,notpick);
}
    int maxValue(vector<vector<int>>& events, int k) {
        // leap of faith in binary search
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
       sort(events.begin(),events.end());
        return solve(0,events,k,dp);
    }
};