class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int n=nums.size();
        int gp=n/k;
        for(auto it:mp){
            if(it.second>gp) return false;
        }
        return n%k==0;
    }
};