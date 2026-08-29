class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> grp;
        unordered_map<int, vector<int>> mp;

        int g = 0;
        mp[g].push_back(temp[0]);
        grp[temp[0]] = g;

        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] - temp[i - 1] > limit)
                g++;

            mp[g].push_back(temp[i]);
            grp[temp[i]] = g;
        }

        vector<int> idx(g + 1, 0);
        vector<int> ans;

        for (int x : nums) {
            int group = grp[x];
            ans.push_back(mp[group][idx[group]++]);
        }

        return ans;
    }
};