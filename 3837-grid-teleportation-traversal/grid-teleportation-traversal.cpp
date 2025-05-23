class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(matrix[0][0] == '#' || matrix[n-1][m-1] == '#') return -1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        // Store teleporter positions
        vector<vector<pair<int, int>>> adj(26);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                char ch = matrix[i][j];
                if(ch >= 'A' && ch <= 'Z') {
                    adj[ch - 'A'].push_back({i, j});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        unordered_set<char> used;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto [dista, pos] = pq.top();
            pq.pop();
            int row = pos.first;
            int col = pos.second;

            /* if(dista > dist[row][col]) continue; */
            if(row == n-1 && col == m-1) return dista;

            // Handle teleporters
            char current = matrix[row][col];
            if(current >= 'A' && current <= 'Z' && used.find(current) == used.end()) {
                used.insert(current);
                for(auto& it : adj[current - 'A']) {
                    int tr = it.first;
                    int tc = it.second;
                    if(dista < dist[tr][tc]) {
                        dist[tr][tc] = dista;
                        pq.push({dista, {tr, tc}});
                    }
                }
            }

            // Handle movement to neighbors
            for(int i = 0; i < 4; ++i) {
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(matrix[nr][nc] == '#') continue;

                if(dista + 1 < dist[nr][nc]) {
                    dist[nr][nc] = dista + 1;
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        return -1; // Destination not reachable
    }
};
