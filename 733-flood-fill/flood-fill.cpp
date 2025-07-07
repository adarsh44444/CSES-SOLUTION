class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        queue<pair<int,pair<int,int>>> q;
        q.push({ini,{sr,sc}});
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            int colour=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();
            ans[row][col]=color;
            for(int i=0;i<4;i++){
                int ar=row+dx[i];
                int ac=col+dy[i];
                if(ar>=0&&ar<n&&ac<m&&ac>=0&&image[ar][ac]==ini&&ans[ar][ac]==-1){
                    q.push({colour,{ar,ac}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ans[i][j]==color) continue;
                else ans[i][j]=image[i][j];
            }
        }
        return ans;
    }
};