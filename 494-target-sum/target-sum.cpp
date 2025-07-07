class Solution {
public:
int dp[21][3000];
int solve(int index,int sum,vector<int> &nums,int target){
    if(index==nums.size()){
        return sum==target;
}   if(dp[index][sum+1000]!=-1) return dp[index][sum+1000];
   int add=0,sub=0;
    add=solve(index+1,sum+nums[index],nums,target);
    sub=solve(index+1,sum-nums[index],nums,target);
    return dp[index][sum+1000]=add+sub;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums,target);        
    }
};