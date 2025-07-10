class Solution {
public:
    #define ll long long
    int maxProduct(vector<int>& nums) {
        ll n = nums.size();
        ll ans = -1e9;
        ll pref = 1, suff = 1;
        for(int i = 0; i < n; i++) {
            pref *= nums[i];
            suff *= nums[n - i - 1];
            ans = max(ans, max(pref, suff));
            if(nums[i] == 0) pref = 1;
            if(nums[n - i - 1] == 0) suff = 1;
        }
        return ans;
    }
};
