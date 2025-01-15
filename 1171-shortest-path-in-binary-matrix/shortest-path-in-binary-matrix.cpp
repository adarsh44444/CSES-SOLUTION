class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Check if the start or end cell is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        // Directions for moving in 8 directions
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
            {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };

        // BFS queue
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark as visited with distance

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            int dist = grid[row][col]; // Current distance

            // Check if we've reached the bottom-right cell
            if (row == n - 1 && col == n - 1) {
                return dist;
            }

            // Explore all 8 directions
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                // Check if the new position is valid and unvisited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                    q.push({newRow, newCol});
                    grid[newRow][newCol] = dist + 1; // Mark visited with distance
                }
            }
        }

        return -1; // No path found
    }
};
