class Solution {
public:
bool isbalanced(unordered_map<char,int> &mp){
    int prev=-1;
    bool flag=true;
    for(auto it:mp){
        if(prev==-1){
            prev=it.second;
        }
        else{
            if(prev!=it.second){
                flag=false;
                break;
            }
        }
    }
    return flag;
}
    int longestBalanced(string s) {
        if(s.size()==1) return 1;
        int n=s.size();
        int i=0,j=0;
        int ans=2;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(isbalanced(mp)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};