class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        vector<pair<int,char>> vec;
        for(auto it:mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end(),[](const pair<int,char> &a,const pair<int,char> &b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        });
        string ans="";
        int n=vec.size();
        for(int i=0;i<n;i++){
            int cnt=vec[i].first;
            char ch=vec[i].second;
            for(int j=0;j<cnt;j++){
                ans+=ch;
            }
        }
        return ans;
    }
};