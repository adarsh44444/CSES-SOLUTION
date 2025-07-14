class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            int curr = mp[s[i]];
            int next = (i + 1 < n) ? mp[s[i + 1]] : 0;

            if (curr < next) {
                // Subtractive case
                total -= curr;
            } else {
                // Normal addition
                total += curr;
            }
        }

        return total;
    }
};
