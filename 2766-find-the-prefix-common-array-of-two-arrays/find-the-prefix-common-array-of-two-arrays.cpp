class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans(n,0);
        int i=0,j=0;
        unordered_map<int,int> mp;
        while(i<n){
            mp[A[i]]++;
            mp[B[j]]++;
            int cnt=0;
            if(A[i]==B[j]){cnt=1;}
            else{
            if(mp[A[i]]==2) cnt++;
            if(mp[B[j]]==2) cnt++;}
            if(i>0) ans[i]=ans[i-1]+cnt;
            else ans[i]=cnt;
            i++;
            j++;
        }
        return ans;
    }
};