class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xori=0;
        for(auto it:nums) xori^=it;
        return xori;
    }
};