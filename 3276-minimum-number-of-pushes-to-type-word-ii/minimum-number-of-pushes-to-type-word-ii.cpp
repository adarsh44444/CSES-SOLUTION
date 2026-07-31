class Solution {
public:
#define ll long long
    int minimumPushes(string word) {
        if(word.size()<=8) return word.size();
        vector<pair<char,int>> vec;
        unordered_map<char,int> mp;
        for(auto it:word){
            mp[it]++;
        }
        for(auto it:mp){
            vec.push_back({it.first,it.second});
        }
        sort(vec.begin(),vec.end(),[](const pair<char,int>&a, const pair<char,int>& b){
            return a.second>b.second;
        });
        ll ans=0;
        for(int i=0;i<vec.size();i++){
            if(i<8) ans+=vec[i].second*1;
            else if(i<16) ans+=vec[i].second*2;
            else if(i<24) ans+=vec[i].second*3;
            else ans+=vec[i].second*4;
        }
        return ans;
    }
};