class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int mid;
        while(low<high){
            mid=(low+high)/2;
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        int n=nums.size();
        int low1=high,high1=n-1;
        int mid1;
        while(low1<=high1){
            mid1=(low1+high1)/2;
            if(nums[mid1]==target) return mid1;
            if(nums[mid1]<target) low1=mid1+1;
            else high1=mid1-1;
        }
        int low2=0,high2=high-1;
        int mid2;
        while(low2<=high2){
            mid2=(low2+high2)/2;
            if(nums[mid2]==target) return mid2;
            if(nums[mid2]<target) low2=mid2+1;
            else high2=mid2-1;
        }
        return -1;
    }
};