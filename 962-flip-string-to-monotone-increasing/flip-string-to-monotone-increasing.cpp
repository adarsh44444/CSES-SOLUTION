class Solution {
public:
int solve(int index,string &s,char prev,vector<vector<int>> &dp){
   if(index==s.size()) return 0;
   int take=1e9,nottake=1e9;
   if(dp[index][prev-'0']!=-1) return dp[index][prev-'0'];
   if(index==0){
    if(s[index]=='0'){
        take=min(take,1+solve(index+1,s,'1',dp));
        nottake=min(nottake,solve(index+1,s,s[index],dp));
    }
    else{
        take=min(take,1+solve(index+1,s,'0',dp));
        nottake=min(nottake,solve(index+1,s,s[index],dp));
    }

   }
   else if(prev=='1'){
    if(s[index]=='0'){
        take=min(take,1+solve(index+1,s,'1',dp));
    }
    else{
        nottake=min(nottake,solve(index+1,s,'1',dp));
    }
   }
   else if(prev=='0'){
    if(s[index]=='0'){
        take=min(take,1+solve(index+1,s,'1',dp));
        nottake=min(nottake,solve(index+1,s,'0',dp));
    }
    else{
        take=min(take,1+solve(index+1,s,'0',dp));
        nottake=min(nottake,solve(index+1,s,'1',dp));
    }
   }
   return dp[index][prev-'0']=min(take,nottake);
}
    int minFlipsMonoIncr(string s) {
        char prev='-1';
        vector<vector<int>> dp(s.size()+1,vector<int>(2,-1));
        return solve(0,s,prev,dp);
    }
};