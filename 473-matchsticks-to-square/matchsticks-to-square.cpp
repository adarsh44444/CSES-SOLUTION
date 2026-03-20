class Solution {
public:
    bool dfs(int idx, vector<int>& matchsticks, vector<int>& sides, int target) {
        if (idx == matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] > target) continue;

            sides[i] += matchsticks[idx];

            if (dfs(idx + 1, matchsticks, sides, target)) return true;

            sides[i] -= matchsticks[idx];

            if (sides[i] == 0) break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int x : matchsticks) sum += x;

        if (sum % 4 != 0) return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sides(4, 0);

        return dfs(0, matchsticks, sides, target);
    }
};