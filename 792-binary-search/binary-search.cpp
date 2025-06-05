class Solution {
public:
int solve(int low,int high,vector<int>&nums,int target,int n){
    if(low>high) return -1;
    int ans=-1;
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    if(nums[mid]>=target){
        ans=solve(low,mid-1,nums,target,n);
    }
    else ans=solve(mid+1,high,nums,target,n);
    return ans;
}
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(0,n-1,nums,target,n);
    }
};