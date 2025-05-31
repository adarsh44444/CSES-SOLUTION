class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &text1,string &text2){
        if(i==0&&j==0){
            return text1[0]==text2[0];
        }
        if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
        int pick=0,notpick=0;
        if(i>=0&&j>=0&&text1[i]==text2[j]){
            pick=1+solve(i-1,j-1,text1,text2);
        }
        if(i>0){
        notpick=solve(i-1,j,text1,text2);}
        if(j>0){
            notpick=max(notpick,solve(i,j-1,text1,text2));
        }
        return dp[i+1][j+1]=max(pick,notpick);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,m-1,text1,text2);
    }
};