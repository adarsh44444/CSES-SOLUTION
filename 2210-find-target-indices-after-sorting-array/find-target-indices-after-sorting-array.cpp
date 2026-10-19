class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt_less=0,cnt_great=0;
        int n=nums.size();
        for(auto it:nums){
            if(it<target) cnt_less++;
            else if(it>target) cnt_great++;
        }
        vector<int> solve;
        int num_idx=n-cnt_less-cnt_great;
        for(int i=0;i<num_idx;i++){
            solve.push_back(cnt_less+i);
        }
        return solve;
    }
};