#define ll long long
class Solution {
public:
    vector<vector<vector<ll>>> dp;

    long long sol(vector<vector<int>>& c, int l, int r, int i) 
    {
        int n = c.size();
        if (i >= n / 2) 
            return 0;

        if (dp[i][l][r] != (-1)) 
            return dp[i][l][r];

        vector<int> lftc, rgtc;
        for (int j = 0; j < 3; j++) 
        {
            if (l != j) 
                lftc.push_back(j);
            if (r != j) 
                rgtc.push_back(j);
        }
        ll ans = 1e14;
        for (int h : lftc) 
        {
            for (int j : rgtc) 
            {
                if (h == j) 
                    continue;
                ll cl = c[i][h], cr = c[n - i - 1][j];
                ans = min(ans, cl + cr + sol(c, h, j, i + 1));
            }
        }
        return dp[i][l][r] = ans;
    }

    long long minCost(int n, vector<vector<int>>& c) {
        dp.resize(n / 2 + 1, vector<vector<ll>>(4, vector<ll>(4, -1)));
        return sol(c, 3, 3, 0);
    }
};