class Solution {
public:
bool iscorrect(int last,int idx,string s){
    string temp="";
    for(int i=last;i<=idx;i++){
        temp+=s[i];
    }
    if(temp.size()==0) return false;
    if(temp.size()>1&&temp[0]=='0') return false;
    if(temp.size()>3) return false;
    int num=stoi(temp);
    if(num<=255&&num>=0) return true;
    return false;
}
void solve(int idx,int cnt,string s,string temp,vector<string> &ans,int last){
    if(cnt==0&&idx==s.size()){
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    for(int j=idx;j<s.size();j++){
        if(iscorrect(idx,j,s)&&cnt>0){
            string original=temp;
            temp+=s.substr(idx,j-idx+1);
            temp+='.';
            solve(j+1,cnt-1,s,temp,ans,j);
            temp=original;
        }
        else{
            break;
        }
    }
    return;
}
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp="";
        solve(0,4,s,temp,ans,0);
        return ans;
    }
};