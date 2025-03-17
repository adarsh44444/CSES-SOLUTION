class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n){
            if(nums[i]!=nums[i+1]) return false;
            i+=2;}
        return true;
    }
};