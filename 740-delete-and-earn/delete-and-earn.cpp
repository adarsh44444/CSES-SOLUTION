class Solution {
public:
#define ll long long
ll dp[100000];
ll ans=0;
ll solve(ll idx,vector<pair<ll,ll>> &temp){
    if(idx==temp.size()-1){ans=max(ans,temp[idx].second); return temp[idx].second;}
    if(idx==temp.size()) return 0;
    ll pick=0;
    if(dp[idx]!=-1) return dp[idx];
    if(idx+1<temp.size()&&temp[idx+1].first-temp[idx].first==1){
        pick=temp[idx].second+solve(idx+2,temp);
    }
    if(idx+1<temp.size()&&temp[idx+1].first-temp[idx].first!=1){
        pick=max(pick,temp[idx].second+solve(idx+1,temp));
    }
    ll notpick=solve(idx+1,temp);
    ans=max({ans,notpick,pick});
    return dp[idx]=max(pick,notpick);
}
    int deleteAndEarn(vector<int>& nums) {
        map<ll,ll> mp;
        memset(dp,-1,sizeof(dp));
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<ll,ll>> temp;
        for(auto it:mp){
            temp.push_back({it.first,it.first*it.second});
        }
        ll temp1=solve(0,temp);
        return ans;
    }
};