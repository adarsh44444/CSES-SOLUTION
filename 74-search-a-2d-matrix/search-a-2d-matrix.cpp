class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool flag=false;
        for(int i=0;i<n;i++){
            if(matrix[i][m-1]<target) {continue;}
            int low=0;
            int high=m-1;
            int mid;
            while(low<=high){
                mid=(low+high)/2;
                if(matrix[i][mid]==target){flag=true;break;}
                else if(matrix[i][mid]>target){high=mid-1;}
                else{low=mid+1;}
            }


        }
        return flag;
    }
};