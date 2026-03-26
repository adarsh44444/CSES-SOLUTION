class Solution {
public:
    void build(vector<int>& arr, int idx, int xorVal, int cnt, unordered_map<int, int>& mp) {
        if (idx == arr.size()) {
            mp[xorVal] = max(mp[xorVal], cnt);
            return;
        }

        // skip
        build(arr, idx + 1, xorVal, cnt, mp);

        // take
        build(arr, idx + 1, xorVal ^ arr[idx], cnt + 1, mp);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = n / 2;

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        unordered_map<int, int> lftmp, rtmp;

        build(left, 0, 0, 0, lftmp);
        build(right, 0, 0, 0, rtmp);

        int ans = -1;

        for (auto &x : lftmp) {
            int val = x.first;
            int cnt = x.second;
            
            int need = target^val;
            if (rtmp.count(need)) {
                ans = max(ans, cnt + rtmp[need]);
            }
        }

        if(ans==-1) return -1;

        return n-ans;
    }
};