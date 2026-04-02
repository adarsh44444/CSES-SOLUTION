class Solution {
public:
void solve(int idx,int k,vector<vector<int>> &ans,vector<int> &temp,int n){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    if(idx>n) return;
    for(int j=idx;j<=n;j++){
        temp.push_back(j);
        solve(j+1,k,ans,temp,n);
        temp.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(1,k,ans,temp,n);
        return ans;
    }
};