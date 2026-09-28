class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(int)st.size());
            if(s[i]=='(') st.push('(');
            else if(s[i]==')') st.pop();
        }
        return ans;
    }
};