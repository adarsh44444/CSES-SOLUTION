class Solution {
public:
    #define ll long long
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == n) return 0;  // If k = 1, there are no cuts, so difference = 0

        vector<ll> temp;
        
        for(int i = 0; i < n - 1; i++) {
            temp.push_back(weights[i] + weights[i + 1]);
        }
        
        sort(temp.begin(), temp.end());
        ll ans = 0;

        // Subtract k-1 smallest values
        for(int i = 0; i < k - 1; i++) {  
            ans -= temp[i];
        }

        // Add k-1 largest values
        for(int i = temp.size() - 1; i >= temp.size() - (k - 1); i--) { 
            ans += temp[i];
        }

        return ans;
    }
};
