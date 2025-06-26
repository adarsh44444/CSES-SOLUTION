class Solution {
public:
int val=0;
void solve(int rowstart,int rowend,int colstart,int colend,vector<vector<int>> &ans){
    int size=rowend-rowstart;
    if(size==1){
        ans[rowstart][colstart]=val++;
        return;
    }
    int midrow=(rowstart+rowend)/2;
    int midcol=(colstart+colend)/2;
    solve(rowstart,midrow,midcol,colend,ans);
    solve(midrow,rowend,midcol,colend,ans);
    solve(midrow,rowend,colstart,midcol,ans);
    solve(rowstart,midrow,colstart,midcol,ans);
}
    vector<vector<int>> specialGrid(int n) {
        int size=1<<n;
        vector<vector<int>> ans(size,vector<int>(size));
        solve(0,size,0,size,ans);
        return ans;
    }
};