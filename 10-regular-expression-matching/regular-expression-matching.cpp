class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length()==0){
            return s.length()==0?1:0;
        }
        bool take=false;
        bool nottake=false;
        if(p[1]=='*'){
            take=p.size()>=2&&isMatch(s,p.substr(2));
            nottake=s.size()>=1&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p);
        }
        else{
            return s.size()>=1&&p.size()>=1&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1),p.substr(1));
        }
        return take||nottake;
    }
};