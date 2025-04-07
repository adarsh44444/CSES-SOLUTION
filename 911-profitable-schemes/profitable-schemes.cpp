class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[101][101][101]; // memo[index][profit][groupCount]

    int solve(int index, int profitLeft, int groupLeft, vector<int>& group, vector<int>& profit) {
        if (index == group.size()) {
            return profitLeft <= 0 ? 1 : 0;
        }

        // Cap the profitLeft at 0 since we only care about >= minProfit
        if (profitLeft < 0) profitLeft = 0;

        if (dp[index][profitLeft][groupLeft] != -1) return dp[index][profitLeft][groupLeft];

        // Option 1: Skip current crime
        int ways = solve(index + 1, profitLeft, groupLeft, group, profit) % MOD;

        // Option 2: Take current crime (if enough group members available)
        if (groupLeft >= group[index]) {
            ways += solve(index + 1, profitLeft - profit[index], groupLeft - group[index], group, profit);
            ways %= MOD;
        }

        return dp[index][profitLeft][groupLeft] = ways;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return solve(0, minProfit, n, group, profit);
    }
};
