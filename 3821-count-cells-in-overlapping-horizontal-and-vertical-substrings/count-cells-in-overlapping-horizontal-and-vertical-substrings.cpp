class Solution {
public:
    vector<int> kmphor(string& s, string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int i = 1, length = 0;

        while (i < n) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int j = 0;
        i = 0;
        vector<int> ans;
        int m = s.size();

        while (j < m) {
            if (pattern[i] == s[j]) {
                i++;
                j++;
                if (i == n) {
                    ans.push_back(j - i);
                    i = lps[i - 1];
                }
            } else {
                if (i > 0) {
                    i = lps[i - 1];
                } else {
                    j++;
                }
            }
        }
        return ans;
    }

    vector<int> kmpver(string& s, string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int i = 1, length = 0;

        while (i < n) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int j = 0;
        i = 0;
        vector<int> ans;
        int m = s.size();

        while (j < m) {
            if (pattern[i] == s[j]) {
                i++;
                j++;
                if (i == n) {
                    ans.push_back(j - i);
                    i = lps[i - 1];
                }
            } else {
                if (i > 0) {
                    i = lps[i - 1];
                } else {
                    j++;
                }
            }
        }
        return ans;
    }

    int countCells(vector<vector<char>>& grid, string pattern) {
        int n = grid.size(), m = grid[0].size();

        string s1 = "", s2 = "";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                s1 += grid[i][j];

        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                s2 += grid[i][j];

        vector<int> ans1 = kmphor(s1, pattern);  // horizontal
        vector<int> ans2 = kmpver(s2, pattern);  // vertical

        vector<int> h1(m * n + 1, 0);
        vector<int> h2(m * n + 1, 0);

        for (int i = 0; i < ans1.size(); i++) {
            h1[ans1[i]]++;
            if (ans1[i] + pattern.size() < m * n)
                h1[ans1[i] + pattern.size()]--;
        }

        for (int i = 1; i < m * n; i++)
            h1[i] += h1[i - 1];

        for (int i = 0; i < ans2.size(); i++) {
            h2[ans2[i]]++;
            if (ans2[i] + pattern.size() < m * n)
                h2[ans2[i] + pattern.size()]--;
        }

        for (int i = 1; i < m * n; i++)
            h2[i] += h2[i - 1];

        int anss = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int hidx = i * m + j;
                int vidx = j * n + i;
                if (h1[hidx] && h2[vidx]) anss++;
            }
        }

        return anss;
    }
};
