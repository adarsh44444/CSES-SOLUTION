class Solution {
public:
    int splitArray(vector<int>& A, int M) {
                int low=*max_element(A.begin(),A.end());
        int high=accumulate(A.begin(),A.end(),0);
        int mid;
        int answer=-1e8;
        int N=A.size();
        if(M>N) return -1;
        while(low<=high){
            mid=(low+high)/2;
            int sum=0;
            int cnt=1;
            for(int i=0;i<N;i++){
                if(sum+A[i]<=mid){
                    sum+=A[i];
                }
                else{
                    cnt++;
                    sum=0;
                    sum=A[i];
                }
            }
            if(cnt>M) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};