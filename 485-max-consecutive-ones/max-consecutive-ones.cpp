class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // two pointer approach
        int i=0,j=0,n=nums.size();
        int ans=0;
        while(j<n){
            if(nums[j]==1) j++;
            else {ans=max(ans,j-i);i=j+1;j=i;}
        }
        ans=max(ans,j-i);
        return ans;
    }
};