class Solution {
public:
int dp[1001][1001];
int solve(int i,int j,string s,string t){
    int n=s.size();
    int m=t.size();
    if(j==m) return 1;
    if(i==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int pick=0,notpick=0;
    if(s[i]==t[j]){
        pick=solve(i+1,j+1,s,t)+solve(i+1,j,s,t);
    }
    else{
    notpick=solve(i+1,j,s,t);}
    return dp[i][j]=notpick+pick;
}
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};