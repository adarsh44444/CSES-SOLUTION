class Solution {
public:
    int solve(int index,vector<string> &arr,int n,set<char> &st){
        if(index==n-1){
            string temp=arr[n-1];
            bool flag=true;
            for(int i=0;i<temp.size();i++){
                if(st.find(temp[i])!=st.end()) {flag=false; break;}
            }
            set<char> st1;
            for(auto it:temp){
                if(st1.find(it)!=st1.end()){
                    flag=false;
                }
                st1.insert(it);
            }
            if(flag) return temp.size();
            return 0;            
        }
        int pick=0,notpick=0;
        notpick=solve(index+1,arr,n,st);
        bool flag=true;
        string temp=arr[index];
        for(int i=0;i<temp.size();i++){
            if(st.find(temp[i])!=st.end()) flag=false;
        }
        set<char> st1;
        for(auto it:temp){
            if(st1.find(it)!=st1.end()) flag=false;
            st1.insert(it);
        }
        if(flag){
            for(auto it:temp){
                st.insert(it);
            }
            pick=temp.size()+solve(index+1,arr,n,st);
        for(int i=0;i<temp.size();i++){
            st.erase(temp[i]);
        }
        }
        return max(pick,notpick);
    }
    int maxLength(vector<string>& arr) {
        set<char> st;
        int n=arr.size();
        return solve(0,arr,n,st);
    }
};