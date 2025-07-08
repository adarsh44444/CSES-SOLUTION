class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 1e9);
        vector<vector<pair<int, pair<int, int>>>> adj(n);
        
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int start = it[2];
            int end = it[3];
            adj[u].push_back({v, {start, end}});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        vis[0] = 0;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > vis[node]) continue;

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int start = it.second.first;
                int end = it.second.second;

                if (time <= end) {
                    int wait = max(start - time, 0);
                    int arrival = time + wait + 1;

                    if (arrival < vis[adjnode]) {
                        vis[adjnode] = arrival;
                        pq.push({arrival, adjnode});
                    }
                }
            }
        }

        return vis[n - 1] == 1e9 ? -1 : vis[n - 1];
    }
};
