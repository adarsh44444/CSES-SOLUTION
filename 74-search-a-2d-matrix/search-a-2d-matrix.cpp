class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=n*m-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            int i=mid/m;
            int j=mid%m;
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};