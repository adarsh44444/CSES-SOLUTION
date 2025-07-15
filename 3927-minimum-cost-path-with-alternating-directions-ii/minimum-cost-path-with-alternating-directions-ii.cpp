class Solution {
public:
#define ll long long

    ll solve(int i, int j, int parity, int m, int n,
             vector<vector<int>> &waitCost,
             vector<vector<vector<ll>>> &dp) {
        
        if (i == m - 1 && j == n - 1) {
            return (i + 1) * (j + 1);
        }

        if (i < 0 || i >= m || j < 0 || j >= n) return 1e18;

        if (dp[i][j][parity] != -1) return dp[i][j][parity];

        ll ans = 1e18;

        if (parity == 1) {
            ans = min(ans, (i + 1) * (j + 1) +
                             min(solve(i + 1, j, !parity, m, n, waitCost, dp),
                                 solve(i, j + 1, !parity, m, n, waitCost, dp)));
        } else {
            ans = min(ans, (ll)waitCost[i][j] +
                             solve(i, j, !parity, m, n, waitCost, dp));
        }

        return dp[i][j][parity] = ans;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(2, -1)));
        return solve(0, 0, 1, m, n, waitCost, dp);
    }
};
