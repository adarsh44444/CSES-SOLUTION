class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int idx=st.top();
                st.pop();
                reverse(s.begin()+idx,s.begin()+i+1);
            }
        }
s.erase(remove(s.begin(), s.end(), '('), s.end());
s.erase(remove(s.begin(), s.end(), ')'), s.end());
return s;
    }
};