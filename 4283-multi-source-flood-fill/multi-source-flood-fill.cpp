class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> result(n,vector<int>(m,0));
        sort(sources.begin(),sources.end(),[](const vector<int> &a,const vector<int> &b){
            return a[2]>b[2];
        });
        queue<tuple<int,int,int,int>> q;
        for(auto it:sources){
            result[it[0]][it[1]]=it[2];
            q.push({it[0],it[1],it[2],0});
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto t=q.front();
                q.pop();
                int i_    = get<0>(t);
                int j_    = get<1>(t);
                int color = get<2>(t);
                int times = get<3>(t);
                for(int ii=0;ii<4;ii++){
                    int nx=i_+dx[ii];
                    int ny=j_+dy[ii];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&result[nx][ny]==0){
                            result[nx][ny]=color;
                        q.push({nx,ny,result[nx][ny],times+1});
                    }
                }
            }
        }
        return result;
    }
};