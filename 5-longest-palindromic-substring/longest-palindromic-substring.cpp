class Solution {
public:
bool fun(int s1, int e, string &s) {
    int i = s1;
    int j = e;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;  // Directly return false if mismatch is found
        }
        i++;
        j--;
    }
    return true;
}

string longestPalindrome(string s) {
    int n = s.size();
    string str = "";
    int maxi = 0;  // Use maxi to track the longest palindrome length

    for (int i = 0; i < n; i++) {  // Check from i to n
        for (int j = n - 1; j >= i; j--) {  // Check from the end to i
            if (s[i] == s[j]) {
                if (fun(i, j, s)) {
                    if (j - i + 1 > maxi) {
                        maxi = j - i + 1;  // Update maxi to the new length
                        str = s.substr(i, maxi);  // Use j - i + 1 for the length
                    }
                }
            }
        }
    }
    return str;
}

};