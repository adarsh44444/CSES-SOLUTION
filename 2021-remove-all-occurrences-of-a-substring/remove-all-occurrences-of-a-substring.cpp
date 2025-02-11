class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        string temp1=s;
        stack<char> st;
        reverse(part.begin(),part.end());
        for(int i=0;i<n;i++){
            st.push(s[i]);
            string temp="";
            bool flag=false;
            if(st.size()>=m){
                int size=st.size();
            for(int i=0;i<size;i++){
                temp+=st.top();
                st.pop();
                if(temp==part){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                reverse(temp.begin(),temp.end());
                for(int i=0;i<temp.size();i++){
                    st.push(temp[i]);
                }
            }}
    }
    string ans="";
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;}
};