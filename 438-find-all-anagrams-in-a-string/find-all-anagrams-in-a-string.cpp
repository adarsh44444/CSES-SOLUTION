class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.size();
        map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[p[i]]++;
        }
        map<char,int> mp2;
        int n1=s.size();
        vector<int> ans;
        int i=0,j=0;
        while(j<n1){
            mp2[s[j]]++;
            if(j-i+1==n){
                bool flag=true;
                for(auto it:mp){
                    if(it.second!=mp2[it.first]){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans.push_back(i);
                mp2[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};