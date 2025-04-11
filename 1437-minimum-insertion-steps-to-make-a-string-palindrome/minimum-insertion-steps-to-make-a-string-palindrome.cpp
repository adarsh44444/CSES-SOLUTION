class Solution {
public:
    int solve(int i,int j,string &s,vector<vector<int>> &dp){
        if(i>j) return 0;
        int ans=1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            ans=min(ans,solve(i+1,j-1,s,dp));
        }
        else{
            ans=min({ans,1+solve(i+1,j,s,dp),1+solve(i,j-1,s,dp)});
        }
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,s.size()-1,s,dp);
    }
};