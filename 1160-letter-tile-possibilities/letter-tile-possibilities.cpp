class Solution {
public:
    void solve(string &tiles, vector<bool> &visited, string &temp, unordered_set<string> &st) {
        for (int i = 0; i < tiles.size(); i++) {
            if (visited[i]) continue;
            
            // Choose the character
            visited[i] = true;
            temp += tiles[i];
            st.insert(temp);

            // Explore further
            solve(tiles, visited, temp, st);

            // Backtrack
            temp.pop_back();
            visited[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        string temp = "";
        vector<bool> visited(tiles.size(), false);
        sort(tiles.begin(), tiles.end()); // Sort to handle duplicates properly
        solve(tiles, visited, temp, st);
        return st.size();
    }
};
