class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int n = s.size();
        // bucket[i] contains characters that appear i times
        vector<vector<char>> bucket(n + 1);
        for (auto &[ch, count] : freq) {
            bucket[count].push_back(ch);
        }

        string ans = "";
        for (int i = n; i > 0; --i) {
            for (char ch : bucket[i]) {
                ans.append(i, ch);  // append character i times
            }
        }

        return ans;
    }
};
