class Solution {
public:
    string processStr(string s) {
        string temp="";
        int n=s.size();
        string result="";
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                result+=result;
            }
            else if(s[i]=='%'){
                reverse(result.begin(),result.end());
            }
            else if(s[i]=='*'){
                if(result.size()>0){
                result.pop_back();}
            }
            else{
                result+=s[i];
            }
        }
        return result;
    }
};