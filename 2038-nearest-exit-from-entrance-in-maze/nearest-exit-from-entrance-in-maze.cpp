class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{entrance[0],entrance[1]}});
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        vis[entrance[0]][entrance[1]]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            if((row==m-1||row==0||col==n-1||col==0)&&(row!=entrance[0]||col!=entrance[1])) return dist;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow<m&&nrow>=0&&ncol>=0&&ncol<n){
                if(maze[nrow][ncol]=='.'&&vis[nrow][ncol]==-1){
                    pq.push({dist+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }

        }
    }
    return -1;}
};