class Solution {
public:
    int dp[21][100000];
    int solve(int index,vector<int> &nums,int target){
        if(index==0){
            if(target+nums[index]==0&&target==nums[index]) return 2;
            if(target+nums[index]==0||target==nums[index]) return 1;
            return 0;
        }
        if(dp[index][target+10000]!=-1) return dp[index][target+10000];
        int notpick=solve(index-1,nums,target+nums[index]);
        int pick=solve(index-1,nums,target-nums[index]);
        return dp[index][target+10000]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums.size()-1,nums,target);
    }
};