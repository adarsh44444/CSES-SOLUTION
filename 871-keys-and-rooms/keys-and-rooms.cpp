class Solution {
public:
void dfs(int node,vector<vector<int>> &rooms,vector<int> &vis){
    vis[node]=1;
    for(int i=0;i<rooms[node].size();i++){
        if(!vis[rooms[node][i]]) dfs(rooms[node][i],rooms,vis);
    }
    return;
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        dfs(0,rooms,vis);
        for(auto it:vis){
            cout<<it<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
    return true;
    }

};