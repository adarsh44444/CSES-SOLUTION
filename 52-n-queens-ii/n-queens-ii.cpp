class Solution {
public:
int cnt=0;
bool left_d(int j,int i,vector<vector<char>> &board){
    bool flag=true;
    while(j>=0&&i>=0){
        if(board[i][j]=='q') {flag=false;break;}
        i--,j--;
    }
    return flag;
}
bool right_d(int j,int i,vector<vector<char>> &board){
    bool flag=true;
    while(j<board[0].size()&&i>=0){
        if(board[i][j]=='q') {flag=false;break;}
        i--,j++;
    }
    return flag;
}
bool move_up(int j,int i,vector<vector<char>> &board){
    bool flag=true;
    while(i>=0){
        if(board[i][j]=='q') {flag=false;break;}
        i--;
    }
    return flag;
}
void solve(int idx,int n,vector<vector<char>> &board){
    if(idx==n-1){
        for(int j=0;j<n;j++){
            if(left_d(j,idx,board)&&right_d(j,idx,board)&&move_up(j,idx,board)){
                cnt++;
            }
        }
        return;
    }
    for(int j=0;j<n;j++){
        if(left_d(j,idx,board)&&right_d(j,idx,board)&&move_up(j,idx,board)){
            board[idx][j]='q';
            solve(idx+1,n,board);
            board[idx][j]='.';
        }
    }
    return;
}
    int totalNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        solve(0,n,board);
        return cnt;
    }
};