class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ans =0;
        int cnt=0;
        for(auto it:nums){
            if(it>0) ans++;
            else if(it<0) cnt++;
        }
        return max(cnt,ans);
    }
};