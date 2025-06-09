class Solution {
public:
int dp[2501][2501];
int solve(int i,vector<int> &nums,int n,int lst){
    if(i==n) return 0;
    int ans=0;
    if(dp[i][lst+1]!=-1) return dp[i][lst+1];
    if(lst==-1){
        ans=max({ans,1+solve(i+1,nums,n,i)});
    }
    else{
        if(nums[i]>nums[lst]){
            ans=max({ans,1+solve(i+1,nums,n,i)});
        }
    }
    ans=max(ans,solve(i+1,nums,n,lst));
    return dp[i][lst+1]=ans;
}
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,nums.size(),-1);
    }
};