class Solution {
public:
#define ll long long
    long long minOperations(vector<int>& nums) {
        ll ans=0;
        for(int i=0;i<nums.size()-1;i++){
            ans+=max(nums[i]-nums[i+1],0);
        }
        return ans;
    }
};