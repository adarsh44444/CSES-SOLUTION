class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{entrance[0],entrance[1]}});
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int n=maze.size(),m=maze[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[entrance[0]][entrance[1]]=1;
        int u=entrance[0];
        int v=entrance[1];
        while(!pq.empty()){
            int cnt=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            if(row==u&&col==v){}
            else if(row==n-1||row==0||col==0||col==m-1) return cnt;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&maze[nrow][ncol]=='.'){
                    vis[nrow][ncol]=1;
                    pq.push({cnt+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};