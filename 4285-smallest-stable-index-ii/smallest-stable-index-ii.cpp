class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi=-1e9;
        int n=nums.size();
        int arr[n];
        for(int i=0;i<n;i++){
            if(nums[i]>=maxi){
                maxi=nums[i];
            }
            arr[i]=maxi;
        }
        int mini=1e9;
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<=mini){
                mini=nums[i];
            }
            arr[i]-=mini;
            if(arr[i]<=k) idx=i;
        }
        return idx;

    }
};