class Solution {
public:
    vector<int> generatea(int row){
        int ans=1;
        vector<int> anss;
        anss.push_back(ans);
        for(int i=1;i<row;i++){
            ans*=(row-i);
            ans/=i;
            anss.push_back(ans);
        }
        return anss;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> roww=generatea(i);
            ans.push_back(roww);
        }
        return ans;
    }
};