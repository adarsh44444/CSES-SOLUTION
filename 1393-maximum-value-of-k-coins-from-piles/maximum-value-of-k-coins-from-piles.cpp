class Solution {
public:
int solve(int i,int k,vector<vector<int>> &piles,vector<vector<int>> &dp){
    if(i==piles.size()||k<=0) return 0;
    int nottaken=-1e9,taken=-1e9;
    if(dp[i][k]!=-1) return dp[i][k];
    int sum=0;
    for(int j=0;j<piles[i].size();j++){
        if(k-(j+1)>=0){
            sum+=piles[i][j];
            taken=max({taken,sum+solve(i+1,k-j-1,piles,dp)}); 
        }
           
    }
    
    nottaken=max({nottaken,solve(i+1,k,piles,dp)});
    return dp[i][k]=max(taken,nottaken);
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,k,piles,dp);
    }
};