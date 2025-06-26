class Solution {
public:
    bool solve(int i, int j, int idx, vector<vector<char>>& board, string& word, vector<vector<int>>& vis) {
        if (idx == word.size()) return true;
        int n = board.size(), m = board[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || board[i][j] != word[idx])
            return false;

        vis[i][j] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; ++k) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            if (solve(nrow, ncol, idx + 1, board, word, vis))
                return true;
        }

        vis[i][j] = 0; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, 0, board, word, vis))
                        return true;
                }
            }
        }
        return false;
    }
};
