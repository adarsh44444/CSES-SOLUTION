class Solution {
public:
bool issafe(int row,int col,int n,vector<vector<string>> &ans,vector<string> &board){
    for(int i=row;i>=0;i--){
        if(board[i][col]=='Q') return false;
    }
    for(int i=col;i>=0;i--){
        if(board[row][i]=='Q') return false;
    }
    for(int i=row,j=col;i>=0&&j>=0;j--,i--){
        if(board[i][j]=='Q') return false;
    }
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}

void solve(int row,int col,int n,vector<vector<string>> &ans,vector<string> &board){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(issafe(row,j,n,ans,board)){
            board[row][j]='Q';
            solve(row+1,j,n,ans,board);
            board[row][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(0,0,n,ans,board);
        return ans;
    }
};