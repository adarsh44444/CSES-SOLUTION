class Solution {
public:
bool solve(int index,vector<int> &nums,vector<int> &dp){
    if(index==nums.size()-1) return true;
    bool ans=false;
    if(dp[index]!=-1) return dp[index];
    for(int i=1;i<=nums[index];i++){
        if(solve(index+i,nums,dp)) return dp[index]=true;
    }
    return dp[index]=false;
}
    bool canJump(vector<int>& nums) { 
        vector<int> dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
};