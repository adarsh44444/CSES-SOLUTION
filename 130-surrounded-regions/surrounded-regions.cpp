class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Step 1: Add all 'O's on the borders to the queue and mark as visited
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                q.push({i, m - 1});
                vis[i][m - 1] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                q.push({0, i});
                vis[0][i] = 1;
            }
            if (board[n - 1][i] == 'O' && !vis[n - 1][i]) {
                q.push({n - 1, i});
                vis[n - 1][i] = 1;
            }
        }

        // Step 2: BFS to mark all 'O's connected to border 'O's
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int adjrow = row + dx[i];
                int adjcol = col + dy[i];
                if (adjrow >= 0 && adjrow < n && adjcol >= 0 && adjcol < m &&
                    board[adjrow][adjcol] == 'O' && !vis[adjrow][adjcol]) {
                    vis[adjrow][adjcol] = 1;
                    q.push({adjrow, adjcol});
                }
            }
        }

        // Step 3: Flip all unvisited 'O's to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
