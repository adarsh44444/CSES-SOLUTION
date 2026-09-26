class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
          unordered_map<string,string> mp;
          for(auto it:knowledge){
            mp[it[0]]=it[1];
          }
          string temp="";
          string ans="";
          int n=s.size();
          bool flag=false;
          for(int i=0;i<n;i++){
            if(s[i]=='('){
                flag=true;
                continue;
            }
            if(s[i]==')'){
                flag=false;
                if(mp.find(temp)!=mp.end()) ans+=mp[temp];
                else ans+='?';
                temp="";
                continue;
            }
            if(!flag){
                ans+=s[i];
            }
            else{
                temp+=s[i];
            }
          }
          return ans;
    }
};