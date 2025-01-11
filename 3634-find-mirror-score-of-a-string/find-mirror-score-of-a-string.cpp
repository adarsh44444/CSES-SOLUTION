class Solution {
public:
    #define ll long long
    long long calculateScore(string s) {
        ll n = s.size();
        ll ans = 0;
        unordered_map<ll, vector<ll>> mp; // Tracks indices of characters

        for (ll i = 0; i < n; i++) {
            ll num = s[i] - 'a';           // Current character's "a"-based index
            ll complement = 25 - num;     // Complementary mirrored index

            // Check if there's a matching complement
            if (mp.find(complement) != mp.end() && !mp[complement].empty()) {
                // Add the distance and remove the last complementary position
                ans += i - mp[complement].back();
                mp[complement].pop_back();
            } else {
                // Otherwise, store the current position for this character
                mp[num].push_back(i);
            }
        }
        return ans;
    }
};
