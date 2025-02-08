class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> index(26, -1); // Store the last occurrence of each letter
        int n = s.size();

        for (int i = 0; i < n; i++) {
            index[s[i] - 'a'] = i;
        }

        vector<bool> seen(26, false);
        string result; // Use string as a stack

        for (int i = 0; i < n; i++) {
            int chara = s[i] - 'a';
            if (seen[chara]) continue; // If the character is already added, skip

            // Maintain increasing order in the result string
            while (!result.empty() && result.back() > s[i] && index[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back(); // Pop from the string
            }

            result.push_back(s[i]); // Add current character
            seen[chara] = true;
        }

        return result;
    }
};
