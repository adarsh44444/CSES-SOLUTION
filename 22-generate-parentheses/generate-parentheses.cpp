class Solution {
public:
vector<string> ans;
void solve(int idx,int o,int c,string &temp,int n){
    if(idx==2*n){
        ans.push_back(temp);
        return;
    }
    if(c==o){
        temp+='(';
        solve(idx+1,o-1,c,temp,n);
    }
    else{
        if(c>o&&c>0){
            string prev=temp;
            temp+=')';
            solve(idx+1,o,c-1,temp,n);
            if(o>0) {
                prev+='(';
                solve(idx+1,o-1,c,prev,n);
            }
        }
    }
}
    vector<string> generateParenthesis(int n) {
        string temp="";
        solve(0,n,n,temp,n);
        return ans;
    }
};