class Solution {
public:
int solve(int index,vector<int> &nums,int target,vector<int> &dp){
    if(target==0) return 1;
    if(target<0) return 0;
    int cnt=0;
    if(dp[target]!=-1) return dp[target];
    for(int i=0;i<nums.size();i++){
        cnt+=solve(index,nums,target-nums[i],dp);
    }
    return dp[target]=cnt;
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(0,nums,target,dp);
    }
};