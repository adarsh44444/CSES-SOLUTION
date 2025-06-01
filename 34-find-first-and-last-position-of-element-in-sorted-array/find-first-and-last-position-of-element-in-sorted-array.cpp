class Solution {
public:
    int findfirst(vector<int> &nums,int target){
        int n=nums.size();
        int low=0,high=n-1;
        int result=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                result=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
    int findlast(vector<int> &nums,int target){
        int n=nums.size();
        int low=0,high=n-1;
        int result=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                result=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=findfirst(nums,target);
        int last=findlast(nums,target);
        return {first,last};
    }
};