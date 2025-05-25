class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0;
        unordered_map<char,int> mp,mp1;
        for(auto it:p){
            mp[it]++;
        }
        int cnt=0;
        int n=s.size();
        vector<int> ans;
        while(j<n){
            while(j-i+1<=p.size()){
                mp1[s[j]]++;
                j++;
            }
            bool flag=true;
            for(auto it:mp){
                char ch=it.first;
                if(mp[ch]!=mp1[ch]){flag=false;break;}
            }
            if(flag) ans.push_back(i);
            mp1[s[i]]--;
            i++;
    }
    return ans;
    }
};