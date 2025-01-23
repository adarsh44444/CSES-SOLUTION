class Solution {
public:
    int solve(int index, vector<vector<int>> &mat, int target, vector<vector<int>> &dp, int offset) {
        if (index == mat.size()) {
            return abs(target); // Base case: return the absolute difference
        }
        if (dp[index][target + offset] != -1) {
            return dp[index][target + offset];
        }

        int result = INT_MAX;
        for (int j = 0; j < mat[0].size(); j++) {
            result = min(result, solve(index + 1, mat, target - mat[index][j], dp, offset));
        }
        return dp[index][target + offset] = result;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int maxSum = 5000; // Maximum possible sum based on constraints
        int offset = maxSum; // Offset to handle negative targets
        vector<vector<int>> dp(mat.size(), vector<int>(2 * maxSum + 1, -1));
        return solve(0, mat, target, dp, offset);
    }
};
