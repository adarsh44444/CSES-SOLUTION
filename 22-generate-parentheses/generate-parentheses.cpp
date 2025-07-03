class Solution {
public:
void solve(vector<string> &ans,string s,int open,int close,int max){
    if(s.size()==2*max){
        ans.push_back(s);
        return;
    }
    if(open<max){
        solve(ans,s+'(',open+1,close,max);
    }
    if(close<open){
        solve(ans,s+')',open,close+1,max);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,"",0,0,n);
        return ans;
    }
};