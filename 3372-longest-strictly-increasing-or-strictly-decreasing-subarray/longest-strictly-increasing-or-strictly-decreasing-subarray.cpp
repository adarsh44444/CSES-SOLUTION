class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[j-1]){
                    maxi=max(maxi,j-i+1);
                }
                else{
                    break;
                }
            }
        }
         for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[j-1]){
                    maxi=max(maxi,j-i+1);
                }
                else{
                    break;
                }
            }}
        return maxi;
        
    }
};