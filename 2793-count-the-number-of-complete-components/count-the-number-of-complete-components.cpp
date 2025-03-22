
class DisjointSet {
    vector<int> rank, parent, size;  // Adding size to count elements in each component
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);  // Initialize size of each component as 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);  // Path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        vector<int> degree(n, 0);  // Stores degree of each node

        for (auto &edge : edges) {
            ds.unionByRank(edge[0], edge[1]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        unordered_map<int, vector<int>> componentNodes;
        for (int i = 0; i < n; i++) {
            int root = ds.findUPar(i);
            componentNodes[root].push_back(i);
        }

        int completeCount = 0;
        for (auto &[root, nodes] : componentNodes) {
            bool isComplete = true;
            int componentSize = nodes.size();
            for (int node : nodes) {
                if (degree[node] != componentSize - 1) {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete) completeCount++;
        }

        return completeCount;
    }
};