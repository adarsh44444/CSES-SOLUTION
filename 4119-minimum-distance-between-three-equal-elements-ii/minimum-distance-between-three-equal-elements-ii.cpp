class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=1e9;
        for(auto it:mp){
            vector<int> &indices=it.second;
            if(indices.size()<3) continue;
            for(int i=0;i<indices.size()-2;i++){
                ans=min(indices[i+1]-indices[i]+indices[i+2]-indices[i+1]+indices[i+2]-indices[i],ans);
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};