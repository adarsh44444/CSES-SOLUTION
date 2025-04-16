class Solution {
public:
#define ll long long
    long long countGood(vector<int>& nums, int k) {
        map<ll, ll> mp;
        int i = 0, j = 0;
        ll n = nums.size();
        ll cnt = 0;
        ll sum = 0;

        while (j < n) {
            ll prev = mp[nums[j]];
            mp[nums[j]]++;
            ll curr = mp[nums[j]];
            sum += (curr * (curr - 1)) / 2 - (prev * (prev - 1)) / 2;

            while (sum >= k) {
                cnt += n - j;

                ll prevFreq = mp[nums[i]];
                mp[nums[i]]--;
                ll currFreq = mp[nums[i]];
                sum -= (prevFreq * (prevFreq - 1)) / 2;
                sum += (currFreq * (currFreq - 1)) / 2;

                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            j++;
        }

        return cnt;
    }
};
