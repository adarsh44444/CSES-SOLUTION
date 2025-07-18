class Solution {
public:
    #define ll long long

    ll solve(ll idx, ll prod, vector<int>& nums, int k, int req, vector<vector<ll>>& dp) {
        if (idx == nums.size()) return 0;
        if (dp[idx][prod + 1] != -1) return dp[idx][prod + 1];

        ll take = 0, nottake = 0;

        if (prod == -1) {
            // Start new subarray
            if (nums[idx] == req)
                take = 1 + solve(idx + 1, nums[idx], nums, k, req, dp);
            else
                take = solve(idx + 1, nums[idx], nums, k, req, dp);

            nottake = solve(idx + 1, -1, nums, k, req, dp);
            dp[idx][prod + 1] = take + nottake;
        } else {
            // Continue existing subarray
            int newProd = (prod * nums[idx]) % k;
            ll count = (newProd == req) ? 1 : 0;
            dp[idx][prod + 1] = count + solve(idx + 1, newProd, nums, k, req, dp);
        }

        return dp[idx][prod + 1];
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] %= k;
        }

        vector<ll> ans(k);
        for (int req = 0; req < k; req++) {
            vector<vector<ll>> dp(nums.size(), vector<ll>(k + 1, -1));
            ans[req] = solve(0, -1, nums, k, req, dp);
        }

        return ans;
    }
};
