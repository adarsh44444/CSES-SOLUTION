class Solution {
public:
int dp[1000];
int solve(int index, vector<int>& nums, int n) {
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];

    int pick = nums[index] + solve(index + 2, nums, n);
    int skip = solve(index + 1, nums, n);

    return dp[index] = max(pick, skip);
}

    int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];  // Special case: only one house

    memset(dp, -1, sizeof(dp));
    int ans1 = solve(0, nums, n - 1);  // Exclude last house

    memset(dp, -1, sizeof(dp));       // Reset DP for second run
    int ans2 = solve(1, nums, n);     // Exclude first house

    return max(ans1, ans2);
}

};