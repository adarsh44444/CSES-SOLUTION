class Solution {
public:
pair<int,int> rowmax(vector<vector<int>>& mat,int col){
    int n=mat.size();
    int maxi=-1;
    int row=-1;
    for(int i=0;i<n;i++){
        if(maxi<mat[i][col]){
            maxi=mat[i][col];
            row=i;
        }
    }
return {maxi,row};
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans;
        int low=0,high=mat[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            pair<int,int> temp=rowmax(mat,mid);
            int el=temp.first;
            int row=temp.second;
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<mat[0].size()?mat[row][mid+1]:-1;
            if(mat[row][mid]>left&&mat[row][mid]>right){
                return {row,mid};
            }
            else if(left>mat[row][mid]) high=mid-1;
            else low=mid+1;
        }
        return {};
    }
};