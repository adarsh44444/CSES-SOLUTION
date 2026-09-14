class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        int n=rooms.size();
        vector<int> vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<rooms[node].size();i++){
                if(vis[rooms[node][i]]==0){
                    q.push(rooms[node][i]);
                    vis[rooms[node][i]]=1;
                }
            }
        }
        for(auto it:vis){
            if(it==0) return false;
        }
        return true;

    }
};