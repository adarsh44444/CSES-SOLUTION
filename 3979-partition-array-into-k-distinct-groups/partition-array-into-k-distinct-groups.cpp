class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int gp=n/k;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]>gp) return false;
        }
        
        /* for(auto it:mp){
            if(it.second>gp) return false;
        } */
        return n%k==0;
    }
};