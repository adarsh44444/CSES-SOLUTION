class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1;
        int high=nums[n-1];
        int mid;
        int ans=0;
        while(low<=high){
            mid=(low+high)/2;
            int num=0;
            for(int i=0;i<n;i++){
                num+=ceil((1.0*nums[i])/mid);
            }
            if(num<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};