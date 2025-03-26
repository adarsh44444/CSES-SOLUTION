class Solution {
public:
    int getnext(int i,int val,vector<vector<int>> &temp){
        int n=temp.size();
        int res=n;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(temp[mid][0]>=val){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
    int solve(int i,vector<vector<int>> &temp,vector<int> &dp){
        if(i==temp.size()||i>temp.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int getnxt=getnext(i+1,temp[i][1],temp);
        int taken=temp[i][2]+solve(getnxt,temp,dp);
        int nottaken=solve(i+1,temp,dp);
        return dp[i]=max(taken,nottaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       int n=profit.size();
       vector<int> dp(n+1,-1);
       vector<vector<int>> temp(n,vector<int>(3,0)); 
       for(int i=0;i<n;i++){
        temp[i][0]=startTime[i];
        temp[i][1]=endTime[i];
        temp[i][2]=profit[i];
       }
       sort(temp.begin(),temp.end());
       return solve(0,temp,dp);

    }
};