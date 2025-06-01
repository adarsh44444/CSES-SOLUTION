class Solution {
public:
    int dp[301][11];
    int solve(int index,vector<int> &jobDifficulty,int d,int n){
        if(d==1){
            int maxi=-1e9;
            for(int i=index;i<n;i++){
                maxi=max(maxi,jobDifficulty[i]);
            }
            return maxi;
        }
        if(dp[index][d]!=-1) return dp[index][d];
        int ans=1e9;
        int maxi=-1e9;
        for(int i=index;i<=n-d;i++){
            maxi=max(maxi,jobDifficulty[i]);
            ans=min(ans,maxi+solve(i+1,jobDifficulty,d-1,n));
        }
        return dp[index][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n) return -1;
        memset(dp,-1,sizeof(dp));
        return solve(0,jobDifficulty,d,n);
    }
};