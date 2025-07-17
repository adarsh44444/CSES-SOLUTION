class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // Correct initialization: vector of vectors of ints
        vector<vector<int>> bucket(nums.size() + 1); // NOT (nums.size()+1, 0)

        for (auto& it : mp) {
            int num = it.first;
            int freq = it.second;
            bucket[freq].push_back(num);
        }

        vector<int> ans;
        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }
};
