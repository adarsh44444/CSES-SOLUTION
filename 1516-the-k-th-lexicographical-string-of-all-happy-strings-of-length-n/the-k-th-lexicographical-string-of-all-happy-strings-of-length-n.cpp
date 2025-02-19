class Solution {
public:
    void solve(int index, string current, vector<string> &temp, int n, char prev) {
        if (index == n) {
            temp.push_back(current);
            return;
        }

        if (prev != 'a') solve(index + 1, current + 'a', temp, n, 'a');
        if (prev != 'b') solve(index + 1, current + 'b', temp, n, 'b');
        if (prev != 'c') solve(index + 1, current + 'c', temp, n, 'c');
    }

    string getHappyString(int n, int k) {
        vector<string> temp;
        solve(0, "", temp, n, 'd');

        // Check if k is within range
        if (k > temp.size()) return "";

        sort(temp.begin(), temp.end());
        return temp[k - 1];  // Convert 1-based index to 0-based
    }
};
