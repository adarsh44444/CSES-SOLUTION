#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
ordered_set* dfs(int node,vector<int> &ans,int parent,vector<vector<pair<int,int>>> &query,vector<int> &xori,vector<vector<int>> &adj,vector<int>& par, vector<int>& vals, vector<vector<int>>& queries){
    if(parent!=-1){
        xori[node]=xori[parent]^vals[node];
    }
    ordered_set* curr=new ordered_set();
    curr->insert(xori[node]);
    for(auto &it:adj[node]){
        ordered_set* child=dfs(it,ans,node,query,xori,adj,par,vals,queries);
    if(curr->size()<child->size()){
        swap(child,curr);
    }
    for(auto &it:*child){
        curr->insert(it);
    }
    delete(child);
    }
    for(auto &it:query[node]){
        int k=it.first;
        int i=it.second;
        ans[i]=k>curr->size()?-1:*curr->find_by_order(k-1);
    }
    return curr;

}
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        int n=par.size();
        vector<int> xori(n);
        xori[0]=vals[0];
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(par[i]==-1) continue;
            adj[par[i]].push_back(i);
        }
        int idx=0;
        vector<vector<pair<int,int>>> query(n);
        for(auto it:queries){
            query[it[0]].push_back({it[1],idx++});
        }
        vector<int> ans(queries.size());
        ordered_set* child=dfs(0,ans,-1,query,xori,adj,par,vals,queries);
        return ans;
    }
};