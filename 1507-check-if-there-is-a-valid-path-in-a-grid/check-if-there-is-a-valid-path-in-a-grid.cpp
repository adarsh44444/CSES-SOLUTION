class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        map<int,vector<pair<int,int>>> mp;
        int n=grid.size(),m=grid[0].size();
        mp[1].push_back({0,1});
        mp[1].push_back({0,-1});
        mp[2].push_back({1,0});
        mp[2].push_back({-1,0});
        mp[3].push_back({1,0});
        mp[3].push_back({0,-1});
        mp[4].push_back({0,1});
        mp[4].push_back({1,0});
        mp[5].push_back({-1,0});
        mp[5].push_back({0,-1});
        mp[6].push_back({0,1});
        mp[6].push_back({-1,0});
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first;
            int j=it.second;
            if(i==n-1&&j==m-1) return true;
            for(auto ti:mp[grid[i][j]]){
                int dx=ti.first;
                int dy=ti.second;
                int nx=dx+i;
                int ny=dy+j;
                if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]) continue;
                for(auto ti1:mp[grid[nx][ny]]){
                    int dx1=ti1.first;
                    int dy1=ti1.second;
                    int nx1=dx1+nx;
                    int ny1=dy1+ny;
    
                    if(nx1==i&&ny1==j){ 
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                    }
                }
            }
        }
        return false;
    }
};