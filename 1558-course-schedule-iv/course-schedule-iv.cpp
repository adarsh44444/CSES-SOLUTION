class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int node, int check){
        if(node == check) return true;
        
        if(vis[node] == 1) return  false;

        vis[node] = 1;

        for(auto neighbor : graph[node]){
            if(dfs(graph, vis, neighbor, check)) return true;
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        for(auto pre:prerequisites)
            graph[pre[0]].push_back(pre[1]);
        
        vector<bool> ans;
        for(auto querry:queries){
            vector<int> vis(numCourses, 0);
            if(dfs(graph, vis, querry[0], querry[1]))
                ans.push_back(true);
            else 
                ans.push_back(false);
        }

        return ans;
    }
};