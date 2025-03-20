class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> temp;
        int n = nums.size();
        
        // Duplicate the array to simulate circular behavior
        temp.insert(temp.end(), nums.begin(), nums.end());
        temp.insert(temp.end(), nums.begin(), nums.end());

        // Use maps instead of direct index access
        unordered_map<int, int> forw, back;
        vector<int> res(2 * n, -1), res2(2 * n, -1);

        // Forward pass
        for (int i = 0; i < 2 * n; i++) {
            int num = temp[i];
            if (forw.find(num) == forw.end()) {
                res[i] = i;
            } else {
                res[i] = forw[num];
            }
            forw[num] = i; // Update last occurrence
        }

        // Backward pass
        for (int i = 2 * n - 1; i >= 0; i--) {
            int num = temp[i];
            if (back.find(num) == back.end()) {
                res2[i] = i;
            } else {
                res2[i] = back[num];
            }
            back[num] = i; // Update last occurrence
        }

        // Calculate final answer array
        vector<int> ans(2 * n, -1);
        for (int i = 0; i < 2 * n; i++) {
            if (res[i] == i && res2[i] == i) {
                ans[i] = -1;
            } else if (res[i] == i) {
                ans[i] = abs(res2[i] - i);
            } else if (res2[i] == i) {
                ans[i] = abs(res[i] - i);
            } else {
                ans[i] = min(abs(res[i] - i), abs(res2[i] - i));
            }
        }

        // Process queries
        vector<int> real;
        for (int it : queries) {
            if (it >= n || it < 0) {  // Ensure index is within bounds
                real.push_back(-1);
                continue;
            }
            int num = min(ans[it + n], ans[it]);
            real.push_back((num == n) ? -1 : num);
        }

        return real;
    }
};