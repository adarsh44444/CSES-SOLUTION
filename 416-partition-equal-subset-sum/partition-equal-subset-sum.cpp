class Solution {
public:
bool check(int index,int sum,vector<int>& nums,vector<vector<int>> &dp){
    if(index==0) return nums[index]==sum;
    bool pick=false,notpick;
    if(dp[index][sum]!=-1) return dp[index][sum];
    notpick=check(index-1,sum,nums,dp);
    if(nums[index]<=sum){
    pick=check(index-1,sum-nums[index],nums,dp);}
    return dp[index][sum]=pick|notpick;
}
    bool canPartition(vector<int>& nums){
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1,-1));
        return check(nums.size()-1,sum/2,nums,dp);
    }
};