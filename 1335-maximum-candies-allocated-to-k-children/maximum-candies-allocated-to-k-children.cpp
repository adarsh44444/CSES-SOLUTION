class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // Binary search approach
        long long low = 1;
        long long high = 1e9;
        long long ans = 0;
        long long sum = accumulate(candies.begin(), candies.end(), 0LL); // Use 0LL to avoid overflow
        
        if (sum < k) return 0;

        int n = candies.size();
        while (low <= high) {
            long long mid = (low + high) / 2; // Change mid to long long
            long long cnt = 0; // Change cnt to long long

            for (int i = 0; i < n; i++) {
                if (mid > 0) {
                    cnt += candies[i] / mid;
                }
            }

            if (cnt >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
