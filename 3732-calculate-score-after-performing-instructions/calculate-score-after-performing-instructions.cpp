class Solution {
public:
    #define ll long long
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        ll n = values.size();
        vector<ll> vis(n, 0);
        ll score = 0;
        ll i = 0;
        vis[0] = 1; // Mark starting point as visited

        while (i < n) {
            string instr = instructions[i];
            ll val = values[i];

            if (instr == "jump") {
                ll temp = i + val;
                if (temp >= n || temp < 0 || vis[temp] == 1) break;
                vis[temp] = 1;
                i = temp;
            } else {
                score += val;
                i++;
                if (i >= n || vis[i]) break;
                vis[i] = 1;
            }
        }

        return score;
    }
};
