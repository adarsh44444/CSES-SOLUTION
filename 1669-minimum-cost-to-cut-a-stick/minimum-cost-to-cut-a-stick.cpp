class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& cuts) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int ind = i; ind <= j; ++ind) {
            int cost = cuts[j + 1] - cuts[i - 1] + 
                       solve(i, ind - 1, cuts) + 
                       solve(ind + 1, j, cuts);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        dp.assign(m, vector<int>(m, -1)); // initialize dp table
        return solve(1, m - 2, cuts);
    }
};
