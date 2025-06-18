class Solution {
public:
int dp[301][301];
int solve(int i,int j,vector<int> &num){
    if(i>j) return 0;
    int ans=-1;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int ind=i;ind<=j;ind++){
        int cnt=num[i-1]*num[ind]*num[j+1]+solve(i,ind-1,num)+solve(ind+1,j,num);
        ans=max(ans,cnt);
    }
    return dp[i][j]=ans;
}
    int maxCoins(vector<int>& nums) {
        vector<int> num;
        memset(dp,-1,sizeof(dp));
        num.push_back(1);
        for(int i=0;i<nums.size();i++){
            num.push_back(nums[i]);
        }
        num.push_back(1);
        int n=num.size();
        return solve(1,n-2,num);
    }
};