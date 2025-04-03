class Solution {
public:
    int solve(int index,vector<int> &satisfaction,int time,vector<vector<int>> &dp){
        if(index==satisfaction.size()) return 0;
        int nottpick=-1e9,pick=-1e9;
        if(dp[index][time]!=-1) return dp[index][time];
        pick=max(pick,satisfaction[index]*time+solve(index+1,satisfaction,time+1,dp));
        nottpick=max(nottpick,solve(index+1,satisfaction,time,dp));
        return dp[index][time]=max(pick,nottpick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,satisfaction,1,dp);
    }
};