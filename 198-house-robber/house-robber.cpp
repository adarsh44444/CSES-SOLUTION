class Solution {
public:
int solve(int index,int n,vector<int> &nums,vector<int> &dp){
    if(index>=n) return 0;
    if(dp[index]!=-1) return dp[index];
    int pick=nums[index]+solve(index+2,n,nums,dp);
    int notpick=0+solve(index+1,n,nums,dp);
    return dp[index]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,n,nums,dp);
    }
};