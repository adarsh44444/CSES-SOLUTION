class Solution {
public:
    int solve(int target, int i, int k, vector<int>& nums, vector<vector<int>>& queries, vector<vector<int>>& dp) {
        if (target == 0) return k;  // Successfully reduced target to zero
        if (k >= queries.size() || target < 0) return queries.size()+1;  // Prevent integer overflow
        
        if (dp[target][k] != -1) return dp[target][k];

        // Option 1: Skip current query
        int res = solve(target, i, k + 1, nums, queries, dp);

        // Option 2: Use current query if it applies to index `i`
        if (queries[k][0] <= i && queries[k][1] >= i) {
            res = min(res, solve(target - queries[k][2], i, k + 1, nums, queries, dp));
        }
        return dp[target][k] = res;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; i++) {
            // Fix: Ensure dp array size is always sufficient
            vector<vector<int>> dp(nums[i]+1, vector<int>(queries.size() + 1, -1));

            int res = solve(nums[i], i, 0, nums, queries, dp);
             // Only consider valid results
                ans = max(ans, res);
        }
        if(ans>queries.size()) return -1;
        return ans;
    }
};
