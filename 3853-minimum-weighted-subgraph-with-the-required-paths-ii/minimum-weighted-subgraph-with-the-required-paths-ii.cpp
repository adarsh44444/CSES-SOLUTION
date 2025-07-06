class Solution {
public:
    // DFS to mark depths, parents (for binary lifting), and cumulative weights
    void dfs(int node, int parent, vector<vector<int>> &up, int wta, vector<int>& cw,
             vector<int>& depth, int level, vector<vector<pair<int, int>>> &adj) {
        depth[node] = level;
        cw[node] = wta;
        up[node][0] = parent;
        for (auto it : adj[node]) {
            int neighbour = it.first;
            int wt = it.second;
            if (neighbour != parent) {
                dfs(neighbour, node, up, wta + wt, cw, depth, level + 1, adj);
            }
        }
    }

    // Preprocessing binary lifting table for kth ancestors
    void markthetable(int n, vector<vector<int>> &up) {
        for (int i = 1; i <= 17; i++) {
            for (int node = 0; node < n; node++) {
                int par = up[node][i - 1];
                if (par != -1) {
                    up[node][i] = up[par][i - 1];
                }
            }
        }
    }

    // Finding the LCA of two nodes using binary lifting
    int findlca(int u, int v, vector<int> &depth, vector<vector<int>> &up) {
        if (depth[u] > depth[v]) {
            swap(u, v);
        }

        int diff = depth[v] - depth[u];
        while (diff > 0) {
            int steps = 31 - __builtin_clz(diff); // safer than log2
            v = up[v][steps];
            diff -= (1 << steps);
        }

        if (u == v) return v;

        for (int j = 17; j >= 0; j--) {
            int u1 = up[u][j];
            int v1 = up[v][j];
            if (u1 == -1 || v1 == -1) continue;
            if (u1 != v1) {
                u = u1;
                v = v1;
            }
        }
        return up[u][0];
    }

    // Compute distance using LCA and cumulative weights
    int dist(int a, int b, vector<int> &cw, vector<int> &depth, vector<vector<int>> &up) {
        int lowest = findlca(a, b, depth, up);
        return cw[a] + cw[b] - 2 * cw[lowest];
    }

    // Main function to process the graph and answer queries
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1; // number of nodes = edges + 1
        vector<vector<int>> up(n, vector<int>(18, -1)); // binary lifting table
        vector<vector<pair<int, int>>> adj(n);

        // Build adjacency list
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> cw(n, 0);       // cumulative weight from root
        vector<int> depth(n, 0);    // depth of each node

        dfs(0, -1, up, 0, cw, depth, 0, adj); // root is 0
        markthetable(n, up); // IMPORTANT: build the binary lifting table

        vector<int> ans;
        for (auto it : queries) {
            int src1 = it[0];
            int src2 = it[1];
            int src3 = it[2];
            int sum = dist(src1, src3, cw, depth, up) +
                      dist(src2, src3, cw, depth, up) +
                      dist(src1, src2, cw, depth, up);
            ans.push_back(sum / 2);
        }

        return ans;
    }
};
