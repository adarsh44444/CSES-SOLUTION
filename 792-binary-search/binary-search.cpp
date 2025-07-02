class Solution {
public:
int ans=-1;
void solve(int low,int high,vector<int> &nums,int target){
    if(low>high) return;
    int mid=(low+high)/2;
    if(nums[mid]==target){
        ans=mid;
        return;
    }
    if(nums[mid]<=target) solve(mid+1,high,nums,target);
    else solve(low,mid-1,nums,target);
}
    int search(vector<int>& nums, int target) {
        solve(0,nums.size()-1,nums,target);
        return ans;
    }
};