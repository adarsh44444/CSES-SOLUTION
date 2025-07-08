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

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> ans;
        DisjointSet ds(c+1);
        int n=connections.size();
        for(int i=0;i<n;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            ds.unionByRank(u,v);
        }
        vector<bool> isdel(c+1,false);
        map<int,set<int>> mp;
        for(int i=1;i<=c;i++){
            mp[ds.findUPar(i)].insert(i);
        }
        for(int i=0;i<queries.size();i++){
            int type=queries[i][0];
            if(type==1){
                int node=queries[i][1];
                if(isdel[node]!=true){
                    ans.push_back(node);
                }
                else{
                    int temp=mp[ds.findUPar(node)].size()==0?-1:*mp[ds.findUPar(node)].begin();
                    ans.push_back(temp);
                }
            }
            else{
                int node=queries[i][1];
                isdel[node]=true;
                mp[ds.findUPar(node)].erase(node);
            }
        }
        return ans;
    }
};