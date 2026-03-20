class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
       unordered_map<int,int> mp;
       for(auto it:nums){
        mp[it]++;
       }
       unordered_map<int,int> req;
       for(auto it:mp){
        req[it.second]++;
       }
       int ans=-1;
       for(auto it:nums){
        if(req[mp[it]]==1){
            ans=it;
            break;
        }
       } 
       return ans;
    }
};