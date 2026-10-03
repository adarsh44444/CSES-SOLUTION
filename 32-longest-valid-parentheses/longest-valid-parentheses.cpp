class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0,close=0;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else close++;
            if(close>open){close=0,open=0;}
            else if(close==open){ans=max(ans,open+close);}
        }
        int ans1=0;
        open=0,close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(close<open){close=0,open=0;}
            else if(close==open){ans=max(ans,open+close);}
        }
        return ans;
    }
};