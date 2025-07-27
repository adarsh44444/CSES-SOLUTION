class Solution {
public:
int dp[501];
int solve(int idx,vector<int> &arr,int k){
    if(idx==arr.size()) return 0;
    int n=arr.size();
    int ans=0;
    int maxi=0;
    if(dp[idx]!=-1) return dp[idx];
    for(int i=idx;i<min(n,idx+k);i++){
        maxi=max(maxi,arr[i]);
        ans=max(ans,(i-idx+1)*maxi+solve(i+1,arr,k));
    }
    return dp[idx]=ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,arr,k);
    }
};