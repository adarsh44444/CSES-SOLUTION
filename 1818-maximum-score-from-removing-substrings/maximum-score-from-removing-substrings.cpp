class Solution {
public:
int solve(string s,char a,char b,int cost,int cost1){
    int ans=0;
    stack<char> st;
    for(auto it:s){
        if(!st.empty()&&it==b&&st.top()==a){
            ans+=cost;
            st.pop();
        }
        else{
            st.push(it);
        }
    }
    string temp;
    while(!st.empty()) {temp+=st.top();st.pop();}
    reverse(temp.begin(),temp.end());
    for(auto it:temp){
        if(!st.empty()&&it==a&&st.top()==b){
            ans+=cost1;
            st.pop();
        }
        else{
            st.push(it);
        }
    }
    return ans;
}
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>=y){
            ans+=solve(s,'a','b',x,y);
            /* ans+=solve(s,'b','a',x,y); */
        }
        else{
            ans+=solve(s,'b','a',y,x);
            /* ans+=solve(s,'a','b',y,x); */
        }
        return ans;
    }
};