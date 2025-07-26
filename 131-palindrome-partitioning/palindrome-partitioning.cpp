class Solution {
public:
bool ispalindrome(string temp1){
    int i=0,j=temp1.size()-1;
    while(i<j){
        if(temp1[i]!=temp1[j]) return false;
        i++;
        j--;
    }
    return true;
}
void solve(int idx,vector<string> &temp,string &s,vector<vector<string>>& ans){
    if(idx==s.size()) { ans.push_back(temp);return;}
    
    for(int i=idx;i<s.size();i++){
        string temp1=s.substr(idx,i-idx+1);
        if(ispalindrome(temp1)){
            temp.push_back(temp1);
            solve(i+1,temp,s,ans);
            temp.pop_back();
        }
    }
    
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,temp,s,ans);
        return ans;
    }
};