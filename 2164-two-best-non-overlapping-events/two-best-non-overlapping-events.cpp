class Solution {
public:
int upperbound(vector<vector<int>> &events,int idx){
    int low=idx+1;int high=events.size()-1;
    int nxt=events.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(events[mid][0]>events[idx][1]){
            high=mid-1;
            nxt=mid;
        }
        else{
            low=mid+1;
        }
    }
    return nxt;
}
int solve(vector<vector<int>> &events,int idx,int k,vector<vector<int>> &dp){
    if(idx>=events.size()||k<=0) return 0;
    if(dp[idx][k]!=-1) return dp[idx][k];
    int nxt=upperbound(events,idx);
    int pick=events[idx][2]+solve(events,nxt,k-1,dp);
    int notpick=solve(events,idx+1,k,dp);
    return dp[idx][k]=max(pick,notpick);
}
    int maxTwoEvents(vector<vector<int>>& events) {

        int n=events.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        sort(events.begin(),events.end());
        return solve(events,0,2,dp);
    }
};