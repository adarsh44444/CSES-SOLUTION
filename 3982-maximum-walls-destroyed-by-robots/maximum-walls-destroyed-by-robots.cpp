#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    vector<vector<ll>> dp;

    // count walls in [l,r]
    ll query(ll l, ll r, vector<int> &walls) {
        if (l > r) return 0;
        ll up = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
        ll low = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        return up - low;
    }

    ll solve(ll i, ll dir, vector<pair<ll,ll>> &vec, vector<int> &walls) {
        if (i <= 0) return 0;  // base: sentinel reached
        if (dp[i][dir] != -1) return dp[i][dir];

        ll ans = 0;
        ll pos = vec[i].first, d = vec[i].second;

        if (dir == 1) { 
            // current robot goes right
            ll l = pos;
            ll r = min(pos + d, vec[i+1].first - 1); // stop before next robot
            ll cur = query(l, r, walls);

            // prev robot ended right or left
            ans = max(ans, solve(i-1,1,vec,walls) + cur);
            ans = max(ans, solve(i-1,0,vec,walls) + cur);
        } 
        else { 
            // current robot goes left
            ll r = pos;
            ll l = max(pos - d, vec[i-1].first + 1); // stop after previous robot
            ll cur = query(l, r, walls);

            // case 1: prev went left (no overlap)
            ans = solve(i-1,0,vec,walls) + cur;

            // case 2: prev went right → possible overlap
            ll overlap = query(l, min(vec[i-1].first + vec[i-1].second, pos-1), walls);
            ans = max(ans, solve(i-1,1,vec,walls) + cur - overlap);
        }

        return dp[i][dir] = ans;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        ll n = robots.size();
        vector<pair<ll,ll>> vec;

        for (int i=0; i<n; i++) vec.push_back({robots[i], distance[i]});
        
        // add sentinels
        vec.push_back({-1000000000LL,0});
        vec.push_back({1000000000LL,0});

        sort(vec.begin(), vec.end());
        sort(walls.begin(), walls.end());

        dp.assign(n+2, vector<ll>(2,-1));

        // last real robot is at index n (0 = left sentinel, n+1 = right sentinel)
        return max(solve(n,1,vec,walls), solve(n,0,vec,walls));
    }
};
