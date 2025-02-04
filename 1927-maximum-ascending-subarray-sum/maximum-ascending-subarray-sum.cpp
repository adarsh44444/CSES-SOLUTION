class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
       //sliding window
       int ans=nums[0];
       int sum=nums[0];
       int i=0,j=1;
       int n=nums.size();
       while(j<n){
        if(nums[j]>nums[j-1]){
            sum+=nums[j];
            ans=max(ans,sum);
        }
        else{
            sum=nums[j];
        }
        j++;
       }
       return ans; 
    }
};