class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> mp;
        for(auto it:bulbs){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second%2==0){

            }
            else{
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};