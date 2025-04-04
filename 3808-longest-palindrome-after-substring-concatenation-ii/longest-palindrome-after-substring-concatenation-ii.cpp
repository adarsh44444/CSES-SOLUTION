class Solution {
public:
	int longestPalindrome(string s, string t) {
		int n = s.size(), m = t.size();
		vector<vector<bool>> ps(n,vector<bool>(n,false));
		vector<int> maxs(n); //maximum length of palindrome in s starting at i
		vector<int> maxt(m); //maximum length of palindrome in t ending at i
		int ans = 0;
		for(int i = n-1; i>= 0; i--) {
			for(int j = i; j < n; j++) {
				ps[i][j] = (j-i == 0) || (j == i + 1 && s[i] == s[j]) || (ps[i+1][j-1] && (s[i] == s[j]));
				if(ps[i][j]) {
					maxs[i] = max(maxs[i], j-i+1);
					ans = max(ans, j-i+1);
				}
			}
		}
		vector<vector<bool>> pt(m,vector<bool>(m,false));
		for(int i = m-1; i>= 0; i--) {
			for(int j = i; j < m; j++) {
				pt[i][j] = (j-i == 0) || (j == i + 1 && t[i] == t[j]) || (pt[i+1][j-1] && (t[i] == t[j]));
				if(pt[i][j]) {
					maxt[j] = max(maxt[j], j-i+1);
					ans = max(ans,j-i+1);
				}
			}
		}

		vector<vector<int>> dp(n,vector<int>(m,0));
		//if(s[i] == t[j]) dp[i][j] = 2 + dp[i-1][j+1]
		for(int i = 0; i < n; i++) {
			for(int j = m-1; j >= 0; j--) {
				if(s[i] == t[j]) {
					if(i > 0 && j < m-1)
						dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 2);
					else
						dp[i][j] = 2;
					int extra = 0;
					if(i + 1 < n) extra = max(extra, maxs[i+1]);
					if(j - 1 >= 0) extra = max(extra, maxt[j-1]);
					ans = max(ans, extra + dp[i][j]);
				}
			}
		}
		return ans;
	}
};