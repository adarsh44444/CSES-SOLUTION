class Solution {
public:
int solve(int index,string s,vector<string> &arr){
    if(index==arr.size()) return 0;
    int pick=0,notpick=0;
    set<char> st;
    string temp=arr[index];
    bool flag=true;
    for(int i=0;i<arr[index].size();i++){
        if(st.find(temp[i])==st.end()){st.insert(temp[i]);}
        else flag=false;
    }
    
    for(int j=0;j<s.size();j++){
        if(st.find(s[j])!=st.end()){
            flag=false;
        }
    }
    if(flag==true){
        pick = max(pick, static_cast<int>(temp.size()) + solve(index + 1, s + temp, arr));

        notpick=max(notpick,solve(index+1,s,arr));
    }
    else{
        notpick=max(notpick,solve(index+1,s,arr));
    }
    return max(pick,notpick);
}
    int maxLength(vector<string>& arr) {
        string s="";
        return solve(0,s,arr);
    }
};