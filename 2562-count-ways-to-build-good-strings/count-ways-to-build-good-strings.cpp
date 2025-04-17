class Solution {
public:
const int mod=1e9+7;
int solve(int size,int low,int high,int zero,int one,vector<int> &dp){
    if(size>high) return 0;
    bool add=false;
    if(size>=low&&size<=high) add=true;
    int take=0;
    if(dp[size]!=-1) return dp[size];
    take+=(solve(size+zero,low,high,zero,one,dp))%mod;
    take+=(solve(size+one,low,high,zero,one,dp))%mod;
    return dp[size]=(add+take)%mod;
}
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(low+high+1,-1);
        return solve(0,low,high,zero,one,dp);
    }
};