class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size(), longestCycle = 0, twoCycleInvitations = 0;
        vector<int> inDegree(n, 0), depth(n, 1);

        for (int person = 0; person < n; ++person)
            inDegree[favorite[person]]++;

        queue<int> q;
        for (int person = 0; person < n; ++person)
            if (inDegree[person] == 0)
                q.push(person);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            int next = favorite[curr];
            depth[next] = max(depth[next], depth[curr] + 1);
            if (--inDegree[next] == 0)
                q.push(next);
        }

        for (int person = 0; person < n; ++person) {
            if (inDegree[person] == 0) continue;
            int cycleLength = 0, curr = person;
            while (inDegree[curr] != 0) {
                inDegree[curr] = 0;
                cycleLength++;
                curr = favorite[curr];
            }
            if (cycleLength == 2)
                twoCycleInvitations += depth[person] + depth[favorite[person]];
            else
                longestCycle = max(longestCycle, cycleLength);
        }

        return max(longestCycle, twoCycleInvitations);
    }
};