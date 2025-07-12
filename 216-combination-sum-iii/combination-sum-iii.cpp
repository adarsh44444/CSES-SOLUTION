class Solution {
public:
void solve(int idx,int k,int n,vector<vector<int>> &ans,vector<int> &temp){
    if(k==0){
        if(n==0){
            ans.push_back(temp);
            return;
        }
    }
    for(int j=idx+1;j<=9;j++){
        /* solve(j,k,n,ans,temp); */
        if(j<=n){
            temp.push_back(j);
            solve(j,k-1,n-j,ans,temp);
            temp.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,k,n,ans,temp);
        return ans;
    }
};