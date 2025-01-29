class Solution {
public:
    int count = 0;
    void solve(vector<int>&nums, int l){
        if(l == nums.size()){
            count++;
        }
        for(int i = l; i<nums.size(); i++){
            swap(nums[i] , nums[l]);
            if( (nums[l]%(l+1))== 0 || (l+1)%nums[l] == 0) {
                solve(nums, l+1);
            }
            swap(nums[i] , nums[l]);
        }
    }
    int countArrangement(int n) {
        vector<int>arr(n);
        for(int i = 0; i<n; i++) arr[i] = i+1;

        solve(arr, 0);
        return count;
    }
};