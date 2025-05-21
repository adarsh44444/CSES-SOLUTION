class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            int num=it.first;
            int freq=it.second;
            if(freq==0) continue;
            while(freq--){
            for(int i=num;i<num+k;i++){
                if(mp[i]==0) return false;
                mp[i]--;
            }
        }}
        return true;
    }
};