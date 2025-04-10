class Solution {
public:
    #define ll long long
    ll dp[20][2][20];

    ll solve(string &s, ll idx, ll tight, ll cnt) {
        if (idx == s.size()) return cnt;
        if (dp[idx][tight][cnt] != -1) return dp[idx][tight][cnt];
        
        ll limit = (tight == 1) ? s[idx] - '0' : 9;
        ll ans = 0;

        for (int i = 0; i <= limit; i++) {
            ll new_cnt = cnt + (i == 1 ? 1 : 0);
            ans += solve(s, idx + 1, tight & (i == s[idx] - '0'), new_cnt);
        }

        return dp[idx][tight][cnt] = ans;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 0);
    }
};
