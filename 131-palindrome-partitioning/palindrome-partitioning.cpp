class Solution {
public:
bool ispalindrome(int i,int j,string&s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void solve(int i,string&s,vector<vector<string>> &ans,vector<string>&curr){
    if(i==s.size()){
        ans.push_back(curr);
        return;
    }
    for(int k=i;k<s.size();k++){
        if(ispalindrome(i,k,s)){
            curr.push_back(s.substr(i,k-i+1));
            solve(k+1,s,ans,curr);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,s,ans,curr);
        return ans;
    }
};