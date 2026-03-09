class Solution {
public:
    string maximumXor(string s, string t) {
        int cnt_1=0,cnt_0=0;
        for(int i=0;i<t.size();i++){
            cnt_1+=t[i]=='1';
            cnt_0+=t[i]=='0';
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(cnt_0>0){
                    ans+=s[i];
                    cnt_0--;
                }
                else{
                    ans+='0';
                    cnt_1--;
                }
            }
            else{
                if(cnt_1>0){
                    ans+='1';
                    cnt_1--;
                }
                else{
                    ans+='0';
                    cnt_0--;
                }
            }
        }
        return ans;
    }
};