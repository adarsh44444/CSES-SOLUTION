class Solution {
public:
int solve(int index,int day,vector<int>& days, vector<int>& costs,vector<vector<int>> &dp){
    if(index==days.size()) return 0;
    int take=1e9,nottake=1e9;
    if(dp[index][day]!=-1) return dp[index][day];
    if(days[index]>day){
        take=min({take,costs[0]+solve(index+1,days[index]+1-1,days,costs,dp),costs[1]+solve(index+1,days[index]+7-1,days,costs,dp),costs[2]+solve(index+1,days[index]+30-1,days,costs,dp)});
    }
    else{
        nottake=min(nottake,solve(index+1,day,days,costs,dp));
    }
    return dp[index][day]=min(take,nottake);
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size()+1,vector<int>(1000,-1));
        return solve(0,0,days,costs,dp);
    }
};