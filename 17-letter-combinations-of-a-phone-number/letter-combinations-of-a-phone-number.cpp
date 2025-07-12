class Solution {
public:
void solve(int idx,string &digits,vector<string> &ans,string temp,map<char,vector<char>> &mp){
    if(idx==digits.size()){
        ans.push_back(temp);
        return;
    }
    for(auto it:mp[digits[idx]]){
        string org=temp;
        temp+=it;
        solve(idx+1,digits,ans,temp,mp);
        temp=org;
    }
}
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> mp;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        vector<string> ans;
        if(digits.size()==0) return ans;
        string temp="";
        solve(0,digits,ans,temp,mp);
        return ans;

    }
};