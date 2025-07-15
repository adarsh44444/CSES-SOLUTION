class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;  // Update frequency for current character
                
                int maxi = INT_MIN;
                int mini = INT_MAX;
                
                // Traverse the map to find min and max frequency
                for (auto it : mp) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                
                sum += (maxi - mini);
            }
        }
        
        return sum;
    }
};