class Solution {
public:
    #define ll long long
    ll mod = 1e9 + 7;

    ll ncr(ll num) {
        // Safely compute nC2 % mod
        return (num * (num - 1) / 2) % mod;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<ll, vector<ll>> mp;
        for (auto it : points) {
            mp[it[1]].push_back(it[0]);
        }

        // Filter out y-levels that can't form segments (less than 2 points)
        map<ll, vector<ll>> mp1;
        for (auto it : mp) {
            ll size = it.second.size();
            if (size >= 2) {
                mp1[it.first] = it.second;
            }
        }

        // ✅ Fix: No trapezoids if less than 2 y-levels have valid segments
        if (mp1.size() <= 1) return 0;

        // Store segment counts
        vector<ll> temp;
        for (auto it : mp1) {
            ll num1 = it.second.size();
            temp.push_back(ncr(num1));  // use corrected ncr
        }

        // Prefix sum and result calculation
        ll n1 = temp.size();
        vector<ll> prefsum(n1, 0);
        ll ans = 0;

        prefsum[0] = temp[0];
        for (int i = 1; i < n1; i++) {
            prefsum[i] = (prefsum[i - 1] + temp[i]) % mod;
        }

        for (int i = 0; i < n1 - 1; i++) {
            ll afterSum = (prefsum[n1 - 1] - prefsum[i] + mod) % mod;
            ans = (ans + temp[i] * afterSum % mod) % mod;
        }

        return ans;
    }
};
