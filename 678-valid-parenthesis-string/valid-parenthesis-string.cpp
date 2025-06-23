class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                low++;
                high++;
            }
            else if(s[i]==')'){
                if(low>0) low--;
                high--;
            }
            else{
                if(low>0) low--;
                high++;
            }
            if(high<0) return 0;
        }
        return low==0;
    }
};