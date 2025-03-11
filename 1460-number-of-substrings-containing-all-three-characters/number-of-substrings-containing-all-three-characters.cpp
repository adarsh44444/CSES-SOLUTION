class Solution {
public:
    #define ll long long
    int numberOfSubstrings(string s) {
        ll ans = 0;
        ll i = 0, j = 0;
        map<char, ll> mp;
        ll n = s.size();
        
        while (j < n) {
            mp[s[j]]++;

            // When all three characters are present
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                ans += (n - j);  // Count all substrings ending at 'j'
                mp[s[i]]--; // Reduce the count of the leftmost character
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]); // Remove if count becomes 0
                }
                i++; // Move left pointer
            }
            j++; // Move right pointer
        }
        return ans;
    }
};
