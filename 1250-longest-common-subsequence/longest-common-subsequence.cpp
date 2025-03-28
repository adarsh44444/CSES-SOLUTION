class Solution {
public:
    int dp[1001][1001]; // Declare the DP array
    
    int solve(int i, int j, const string &text1, const string &text2) {
        if (i >= text1.size() || j >= text2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2);
        } else {
            dp[i][j] = max(solve(i + 1, j, text1, text2), solve(i, j + 1, text1, text2));
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp)); // Properly initialize DP array
        return solve(0, 0, text1, text2);
    }
};
