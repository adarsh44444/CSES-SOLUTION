class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == ch) return false; // check column
            if(board[row][i] == ch) return false; // check row
            // check 3x3 box
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if(solve(board)) return true;
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; // board completely filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
