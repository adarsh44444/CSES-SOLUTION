class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findupar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findupar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ulp = findupar(u);
        int vlp = findupar(v);
        if (ulp == vlp) return;
        if (rank[ulp] < rank[vlp]) {
            parent[ulp] = vlp;
        } else if (rank[vlp] < rank[ulp]) {
            parent[vlp] = ulp;
        } else {
            parent[ulp] = vlp;
            rank[vlp]++;
        }
    }
};

class Solution {
public:
#define ll long long

    bool solve(ll mid, int n, vector<vector<int>> &edges, int k) {
        ll cnt = 0;
        DisjointSet ds(n);
        vector<vector<int>> temp;

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int s = it[2];
            int must = it[3];

            if (must == 1) {
                if (s < mid) return false;
                ds.unionbyrank(u, v);
            } else {
                if (s >= mid) {
                    ds.unionbyrank(u, v);
                } else if (2 * s >= mid) {
                    temp.push_back({2 * s, u, v});
                }
            }
        }

        for (auto &it : temp) {
            int u = it[1];
            int v = it[2];
            if (ds.findupar(u) != ds.findupar(v)) {
                ds.unionbyrank(u, v);
                cnt++;
                if (cnt > k) return false;
            }
        }

        // Correct connectivity check
        int root = ds.findupar(0);
        for (int i = 1; i < n; i++) {
            if (ds.findupar(i) != root) return false;
        }

        return true;
    }

    int maxStability(int n, vector<vector<int>> &edges, int k) {
        int low = 1, high = 1e9, ans = -1;
        bool flag=true;
        DisjointSet ds(n);
        for(auto it:edges){
            int must=it[3];
            if(must==1){
                if(ds.findupar(it[1])==ds.findupar(it[0])){flag=false; break;}
                ds.unionbyrank(it[0],it[1]);
            }
        }
        if(flag==false) return -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (solve(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
