class Solution {
public:
    bool solve(int index,vector<int> &nums,int target,vector<vector<int>> &dp){
        if(index==nums.size()-1) return nums[index]==target;
        if(target==0) return 1;
        bool ans=false;
        if(dp[index][target]!=-1) return dp[index][target];
        if(target-nums[index]>=0){
        ans|=solve(index+1,nums,target-nums[index],dp);}
        ans|=solve(index+1,nums,target,dp);
        return dp[index][target]=ans;
    }
    bool canPartition(vector<int>& nums) {
        // main logic is can we divide it into two equal halfes
        long long sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(sum%2!=0) return 0;
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        return solve(0,nums,sum/2,dp);
    }
};