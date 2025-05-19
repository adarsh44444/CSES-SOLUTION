class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        int suff=1;
        for(int i=n-2;i>=0;i--){
            suff*=nums[i+1];
            prefix[i]*=suff;
        }
        return prefix;
    }
};