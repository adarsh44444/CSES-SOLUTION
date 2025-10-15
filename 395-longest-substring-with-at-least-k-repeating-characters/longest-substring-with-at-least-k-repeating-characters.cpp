#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestSubstring(std::string s, int k) {
        return longestSubstringRecursive(s, 0, s.length(), k);
    }

private:
    int longestSubstringRecursive(const std::string& s, int start, int end, int k) {
        if (end - start < k) {
            return 0;
        }

        std::vector<int> freq(26, 0);
        for (int i = start; i < end; ++i) {
            freq[s[i] - 'a']++;
        }

        int splitIndex = -1;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0 && freq[i] < k) {
                for (int j = start; j < end; ++j) {
                    if (s[j] - 'a' == i) {
                        splitIndex = j;
                        break;
                    }
                }
                break;
            }
        }

        if (splitIndex == -1) {
            return end - start;
        }

        int maxLen = 0;
        int currentStart = start;
        for (int i = start; i < end; ++i) {
            if (freq[s[i] - 'a'] < k) {
                maxLen = std::max(maxLen, longestSubstringRecursive(s, currentStart, i, k));
                currentStart = i + 1;
            }
        }
        maxLen = std::max(maxLen, longestSubstringRecursive(s, currentStart, end, k));

        return maxLen;
    }
};