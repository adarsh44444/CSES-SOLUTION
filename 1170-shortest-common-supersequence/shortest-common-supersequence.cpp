class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i1=n;
        string ans="";
        int j1=m;
        while(i1>0&&j1>0){
            if(str1[i1-1]==str2[j1-1]){
                ans+=str1[i1-1];
                i1--;
                j1--;
            }
            else if(dp[i1-1][j1]>dp[i1][j1-1]){
                ans+=str1[i1-1];
                i1--;
            }
            else{
                ans+=str2[j1-1];
                j1--;
            }

            }
            while(i1>0){
                ans+=str1[i1-1];
                i1--;
            }
            while(j1>0){
                ans+=str2[j1-1];
                j1--;
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }

    
};