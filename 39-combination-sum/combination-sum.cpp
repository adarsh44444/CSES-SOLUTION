class Solution {
public:
void solve(int i,vector<int> &candidates,int target,vector<int> temp,vector<vector<int>> &ans){
    if(i==candidates.size()){
        if(target==0){
        ans.push_back(temp);}
        return;
    }
    if(target<0) return;
    if(candidates[i]<=target){
        temp.push_back(candidates[i]);
        solve(i,candidates,target-candidates[i],temp,ans);
        temp.pop_back();
    }
    solve(i+1,candidates,target,temp,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,candidates,target,temp,ans);
        return ans;
    }
};