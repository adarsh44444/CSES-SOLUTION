class Solution {
public:
#define ll long long
ll dp[200001][2][2];
ll solve(ll idx,vector<int> &nums,ll parity,ll prev,ll n){
    if(idx==n) return 0;
    ll ans=0;
    if(parity==1){
        if(prev==0&&nums[idx]==1){
            ans=max(ans,1+solve(idx+1,nums,parity,1,n));
        }
        else if(prev==1&&nums[idx]==0){
            ans=max(ans,1+solve(idx+1,nums,parity,0,n));
        }
        else{
            ans=max(ans,solve(idx+1,nums,parity,prev,n));
        }
    }
    else{
        if(prev==0&&nums[idx]==0){
            ans=max(ans,1+solve(idx+1,nums,parity,0,n));
        }
        else if(prev==1&&nums[idx]==1){
            ans=max(ans,1+solve(idx+1,nums,parity,1,n));
        }
        else{
            ans=max(ans,solve(idx+1,nums,parity,prev,n));
        }
    }
    return ans;
}
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        ll ans=0;
        memset(dp,-1,sizeof(dp));
        ans=max(ans,solve(0,nums,1,0,n));
        memset(dp,-1,sizeof(dp));
        ans=max(ans,solve(0,nums,1,1,n));
        memset(dp,-1,sizeof(dp));
        ans=max(ans,solve(0,nums,0,1,n));
        memset(dp,-1,sizeof(dp));
        ans=max(ans,solve(0,nums,0,0,n));
        return ans;
    }
};