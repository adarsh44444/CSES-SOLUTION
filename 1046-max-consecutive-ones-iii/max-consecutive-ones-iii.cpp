class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int cnt=0;
        int ans=0;
        while(r<nums.size()){
            if(nums[r]==0){
                cnt++;
            }
            while(cnt>k){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};