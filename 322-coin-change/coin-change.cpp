class Solution {
public:
int dp[13][100001];
int solve(int index,vector<int> &coins,int amount){
    if(index==0){
        if(amount%coins[index]==0) return amount/coins[index];
        else return 1e9;
    }
    if(dp[index][amount]!=-1) return dp[index][amount];
    int pick=0,notpick=0;
    int ans=1e9;
    if(coins[index]<=amount){
        ans=min({ans,1+solve(index-1,coins,amount-coins[index]),1+solve(index,coins,amount-coins[index])});
    }
    ans=min(ans,solve(index-1,coins,amount));
    return dp[index][amount]=ans;
}
    int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

    // Base case: using only the first coin
    for (int j = 0; j <= amount; j++) {
        if (j % coins[0] == 0)
            dp[0][j] = j / coins[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= amount; j++) {
            // Not pick the coin
            int notPick = dp[i - 1][j];

            // Pick the coin (could be the same coin again)
            int pick = 1e9;
            if (coins[i] <= j)
                pick =min(1+dp[i-1][j-coins[i]], 1 + dp[i][j - coins[i]]);

            dp[i][j] = min(pick, notPick);
        }
    }

    return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
}

};