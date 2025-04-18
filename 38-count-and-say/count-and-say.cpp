class Solution {
public:
string solve(int n,string &temp){
    string ans="";
    int cnt=1;
    for(int i=0;i<temp.size()-1;i++){
        if(temp[i]!=temp[i+1]){
            ans+=to_string(cnt);
            ans+=temp[i];
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    ans+=to_string(cnt);
    ans+=temp[temp.size()-1];
    return ans;

}
    string countAndSay(int n) {
        string temp="1";
        for(int i=2;i<=n;i++){
            temp=solve(i,temp);
        }
        return temp;
    }
};