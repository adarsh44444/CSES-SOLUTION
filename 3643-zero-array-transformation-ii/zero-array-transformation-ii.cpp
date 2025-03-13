class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0;
        int n = nums.size();
        int high = queries.size();
        
        while (low <= high) {
            vector<int> temp(n, 0);
            int mid = (low + high) / 2;

            for (int i = 0; i < mid; i++) {
                temp[queries[i][0]] += -queries[i][2];
                if (queries[i][1] + 1 < n) {
                    temp[queries[i][1] + 1] += queries[i][2];
                }
            }

            for (int i = 1; i < n; i++) {
                temp[i] += temp[i - 1];
            }

            bool flag = true;  // Start with true
            for (int i = 0; i < n; i++) {
                if (nums[i] + temp[i] > 0) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(low>queries.size()) return -1;
        return low;
    }
};
