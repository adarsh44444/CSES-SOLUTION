class Solution {
public:
    #define ll long long
    const ll mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;

        // Find Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Find Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll left = i - pse[i];
            ll right = nse[i] - i;
            ans = (ans + (1LL * arr[i] * left % mod * right % mod)) % mod;
        }

        return ans;
    }
};
