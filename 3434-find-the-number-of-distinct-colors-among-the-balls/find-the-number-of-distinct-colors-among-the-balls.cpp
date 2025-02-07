class Solution {
public:
    #define ll long long
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        unordered_map<ll, ll> dist; 
        unordered_map<ll, ll> color;
        
        for (auto &it : queries) {
            ll node = it[0];
            ll colors = it[1];

            if (dist.find(node) != dist.end()) {  
                color[dist[node]]--;  
                if (color[dist[node]] == 0) {
                    color.erase(dist[node]); 
                }
            }

            dist[node] = colors;
            color[colors]++;  
            
            res.push_back(color.size());
        }
        
        return res;
    }
};
