class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& comp) {
        vis[node] = 1;
        comp.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, comp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            vector<int> comp;
            dfs(i, adj, vis, comp);

            bool complete = true;

            for (int node : comp) {
                if (adj[node].size() != comp.size() - 1) {
                    complete = false;
                    break;
                }
            }

            if (complete) ans++;
        }

        return ans;
    }
};