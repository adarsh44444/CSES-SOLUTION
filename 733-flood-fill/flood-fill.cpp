class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=image[i][j];
            }
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        ans[sr][sc]=color;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int adjrow=row+dx[i];
                int adjcol=col+dy[i];
                if(adjrow>=0&&adjrow<n&&adjcol>=0&&adjcol<m&&image[adjrow][adjcol]==inicolor&&ans[adjrow][adjcol]!=color){
                    q.push({adjrow,adjcol});
                    ans[adjrow][adjcol]=color;
                }
            }
        }
        return ans;
    }
};