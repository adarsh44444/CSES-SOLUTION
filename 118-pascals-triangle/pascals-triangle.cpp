class Solution {
public:
#define ll long long
vector<int> solve(int n){
    ll ans=1;
    vector<int> anss;
    anss.push_back(ans);
    for(int i=1;i<n;i++){
        ans*=(n-i);
        ans/=i;
        anss.push_back(ans);
    }
    return anss;
}
    vector<vector<int>> generate(int numRows) {
vector<vector<int>> ans;
    for(int i=1;i<=numRows;i++){
        ans.push_back(solve(i));
    }
    return ans;
    }
};