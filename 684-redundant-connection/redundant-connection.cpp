class Solution {
public:
    int n;
    vector<int> parent;

    int findupar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findupar(parent[node]); // Path compression
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        parent.resize(n + 1);
        
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int p1 = findupar(u);
            int p2 = findupar(v);

            if (p1 == p2) {
                return {u, v}; // This edge forms a cycle
            } else {
                parent[p1] = p2; // Union the sets
            }
        }
        return {};
    }
};
