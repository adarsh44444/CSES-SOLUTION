class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt>0){
                    temp+='(';
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt>0){
                    temp+=')';
                }
            }
        }
        return temp;
    }
};