class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        int diff=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            if(row==n-1&&col==m-1) return dist[n-1][m-1];
            pq.pop();
            for(int i=0;i<4;i++){
                int adjrow=row+delrow[i];
                int adjcol=col+delcol[i];
                if(adjrow>=0&&adjrow<n&&adjcol>=0&&adjcol<m){
                    if(dist[adjrow][adjcol]>max(diff,abs(heights[row][col]-heights[adjrow][adjcol]))){
                        dist[adjrow][adjcol]=max(diff,abs(heights[row][col]-heights[adjrow][adjcol]));
                        pq.push({dist[adjrow][adjcol],{adjrow,adjcol}});
                    }
                }
            }
        }
        return -1;
    }
};