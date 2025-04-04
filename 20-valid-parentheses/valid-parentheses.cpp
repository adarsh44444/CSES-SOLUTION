class Solution {
public:
    bool isValid(string s) {
        map<char,char> mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        stack<char> st;
        for(auto it:s){
            if(mp.find(it)==mp.end()){
                st.push(it);
            }
            else{
                if(!st.empty()&&mp[it]==st.top()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};