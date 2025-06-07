class Solution {
public:
    #define ll long long
    ll mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n), pse(n, -1);
        stack<int> st;

        // Compute Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        // ❗ Clear stack before reuse
        while (!st.empty()) st.pop();

        // Compute Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        // Calculate the answer
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll left = i - pse[i];
            ll right = nse[i] - i;
            ans = (ans + (arr[i] * left % mod) * right % mod) % mod;
        }
        return ans;
    }
};
