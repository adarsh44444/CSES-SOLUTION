class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int pos=0,neg=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pos*2]=nums[i];
                pos++;
            }
            else{
                ans[neg*2+1]=nums[i];
                neg++;
            }
            
        }
        return ans;

    }
};