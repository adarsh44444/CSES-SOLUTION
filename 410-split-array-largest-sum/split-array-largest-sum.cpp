class Solution {
public:
bool solve(int mid,vector<int> &nums,int k){
    int n=nums.size();
    int cnt=1;
    int curr=0;
    for(int i=0;i<n;i++){
        if(curr+nums[i]<=mid){
            curr+=nums[i];
        }
        else{
            curr=nums[i];
            cnt++;
        }
    }
    return cnt<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=1e9;
        int mid;
        int ans;
        while(low<=high){
            mid=(low+high)/2;
            if(solve(mid,nums,k)) {ans=mid; high=mid-1;}
            else low=mid+1;
        }
        return ans;
    }
};