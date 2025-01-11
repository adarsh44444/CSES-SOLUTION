class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        int odd=0,even=0;
        for(auto it:mp){
            if(it.second%2==0) even++;
            else odd++;
        }
        if(odd>k||s.size()<k) return false;
        return true;
    }
};