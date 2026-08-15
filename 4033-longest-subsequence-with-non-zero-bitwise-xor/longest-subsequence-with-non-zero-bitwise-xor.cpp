class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) cnt++;
        }
        if(cnt==0) return 0;
        set<int> st;
        int xori=0;
        for(auto it:nums){
            st.insert(it);
            xori=xori^it;
        }
        if(st.size()==1) return n%2==0?n-1:n;
        return xori==0?n-1:n;
    }
};