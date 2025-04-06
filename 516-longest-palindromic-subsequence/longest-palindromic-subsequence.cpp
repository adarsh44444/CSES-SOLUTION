class Solution {
public:
int solve(int i,int j,string &s,string &s2,vector<vector<int>> &dp){
    if(i==s.size()||j==s2.size()) return 0;
    int pick=-1e9,notpick=-1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s2[j]){
        pick=max({pick,1+solve(i+1,j+1,s,s2,dp)});
    }
    notpick=max({notpick,solve(i+1,j,s,s2,dp),solve(i,j+1,s,s2,dp)});
    return dp[i][j]=max(pick,notpick);
}
    int longestPalindromeSubseq(string s) {
        string s2=s;
    reverse(s2.begin(),s2.end());
    int n=s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(0,0,s,s2,dp);
    }
};