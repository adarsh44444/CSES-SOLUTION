class Solution {
public:
#define ll long long
ll dp[501][501][3];
ll solve(ll i,ll j,vector<vector<int>> &coins,ll cnt){
    ll m=coins.size(),n=coins[0].size();
    if(i>=m||j>=n) return -1e9;
    if(i==m-1&&j==n-1){
        if(coins[i][j]>=0) return coins[i][j];
        else{
            if(cnt>0) return 0;
            else return coins[i][j];
        }
    }
    if(dp[i][j][cnt]!=-1e9) return dp[i][j][cnt];
    ll ans=-1e9;
    if(coins[i][j]>=0){
    ans=max({ans,coins[i][j]+solve(i+1,j,coins,cnt),coins[i][j]+solve(i,j+1,coins,cnt)});}
    else{
        if(cnt>0){
            ans=max({ans,0+solve(i+1,j,coins,cnt-1),0+solve(i,j+1,coins,cnt-1),coins[i][j]+solve(i,j+1,coins,cnt),coins[i][j]+solve(i+1,j,coins,cnt)});
        }
        else{
            ans=max({ans,coins[i][j]+solve(i+1,j,coins,cnt),coins[i][j]+solve(i,j+1,coins,cnt)});
        }
    }
    return dp[i][j][cnt]=ans;

}
    int maximumAmount(vector<vector<int>>& coins) {
        ll m=coins.size(),n=coins[0].size();
        for(int i=0;i<501;i++){
    for(int j=0;j<501;j++){
        for(int k=0;k<3;k++){
            dp[i][j][k] = -1e9;
        }
    }
}
        return solve(0,0,coins,2);
    }
};