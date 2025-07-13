class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        // multisource destination all reachble
        // constraints is n =100
        // typical o(n^3) solutions is possible;
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(auto it:edges){
            int i=it[0];
            int j=it[1];
            int wt=it[2];
            matrix[i][j]=wt;
            matrix[j][i]=wt;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) matrix[i][j]=0;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int ans=0;
        int maxi=1e9;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=threshold) cnt++;
            }
            if(cnt<=maxi) {maxi=cnt; ans=i;}
        }
        return ans;

    }
};