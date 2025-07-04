class Solution {
public:
#define ll long long
ll dp[201][20001];
bool solve(int idx,vector<int> &nums,ll target){
    if(idx==nums.size()) return target==0;
    bool ans=false;
    if(dp[idx][target]!=-1) return dp[idx][target];
    ans|=solve(idx+1,nums,target);
    if(target>=nums[idx]){
        ans|=solve(idx+1,nums,target-nums[idx]);
    }
    return dp[idx][target]=ans;
}
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        ll sum=accumulate(nums.begin(),nums.end(),0ll);
        if(sum%2!=0) return false;
        return solve(0,nums,sum/2);
    }
};