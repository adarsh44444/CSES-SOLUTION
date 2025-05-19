class Solution {
public:
    int solve(int i,vector<int> &nums,vector<int> &dp){
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()) return 0;
        int ans=-1;
        if(dp[i]!=-1) return dp[i];
        int pick,notpick;
        pick=nums[i]+solve(i+2,nums,dp);
        notpick=solve(i+1,nums,dp);
        ans=max(pick,notpick);
        return dp[i]=ans;
    }
    int rob(vector<int>& nums) {
        // pick or notpick problem
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,nums,dp);
    }
};