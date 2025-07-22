class Solution {
public:
    vector<vector<vector<int>>> dp;

    vector<int> solve(int idx, int previdx, vector<int>& nums) {
        if (idx == nums.size()) return {};

        // Check memo table
        if (dp[previdx + 1][idx].size() != 0) return dp[previdx + 1][idx];

        vector<int> notTake = solve(idx + 1, previdx, nums);
        vector<int> take;

        if (previdx == -1 || nums[idx] % nums[previdx] == 0) {
            take = solve(idx + 1, idx, nums);
            take.insert(take.begin(), nums[idx]);
        }

        return dp[previdx + 1][idx] = (take.size() > notTake.size() ? take : notTake);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dp.assign(n + 1, vector<vector<int>>(n, vector<int>()));
        return solve(0, -1, nums);
    }
};
