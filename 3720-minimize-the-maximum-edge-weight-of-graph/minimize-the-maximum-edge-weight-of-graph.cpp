class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int mini = 1e9;
        int maxi = -1e9;
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            mini = min(mini, w);
            maxi = max(maxi, w);

       /*      adj[u].push_back({v, w}); */
            adj[v].push_back({u, w});  // Since it's an undirected graph
        }

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it.first]) {
                    q.push(it.first);
                    vis[it.first] = 1;
                }
            }
        }

        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 0) return -1;
        }

        int mid;
        while (mini <= maxi) {
            mid = (mini + maxi) / 2;
            vector<int> vis(n, 0);
            queue<int> q;
            q.push(0);
            vis[0] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto it : adj[node]) {
                    if (!vis[it.first] && mid >= it.second) {  // Fix the condition
                        q.push(it.first);
                        vis[it.first] = 1;
                    }
                }
            }

            bool flag = false;
            for (int i = 0; i < vis.size(); i++) {
                if (vis[i] == 0) flag = true;
            }

            if (flag) {
                mini = mid + 1;
            } else {
                maxi = mid - 1;
            }
        }

        return mini;
    }
};
