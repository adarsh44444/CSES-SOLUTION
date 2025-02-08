class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";  // Edge case: remove all digits

        stack<char> st;
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;  // Remove one digit
            }
            st.push(digit);
        }

        // Remove remaining k digits from the back if needed
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result string
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end()); // Reverse the stack output

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};
