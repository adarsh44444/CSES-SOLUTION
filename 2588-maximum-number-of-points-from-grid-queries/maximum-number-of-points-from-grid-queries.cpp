class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(queries.size(), 0);
        vector<pair<int, int>> sortedQueries;
        
        for (int i = 0; i < queries.size(); i++)
            sortedQueries.push_back({queries[i], i});
        
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int count = 0;
        int lastQueryValue = 0;
        int queryIndex = 0;

        while (!pq.empty() && queryIndex < queries.size()) {
            if (pq.empty()) break;  // ✅ Prevents runtime error

            int currValue = pq.top().first;

            while (queryIndex < queries.size() && sortedQueries[queryIndex].first <= lastQueryValue) {
                ans[sortedQueries[queryIndex].second] = count;
                queryIndex++;
            }

            if (queryIndex >= queries.size()) break;  // ✅ Prevents out-of-bounds access

            while (!pq.empty() && pq.top().first < sortedQueries[queryIndex].first) {
                auto [value, pos] = pq.top();
                pq.pop();
                int row = pos.first, col = pos.second;
                count++;
                
                for (int i = 0; i < 4; i++) {
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];

                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                    }
                }
            }

            lastQueryValue = sortedQueries[queryIndex].first;
        }

        while (queryIndex < queries.size()) {
            ans[sortedQueries[queryIndex].second] = count;
            queryIndex++;
        }

        return ans;
    }
};
