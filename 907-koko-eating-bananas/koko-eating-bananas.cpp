class Solution {
public:
#define ll long long
    int minEatingSpeed(vector<int>& piles, int h) {
        ll low = 1;
        ll high = *max_element(piles.begin(), piles.end());
        ll mid;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            ll hr = 0;
            
            // Calculate the total hours needed with eating speed 'mid'
            for (ll i = 0; i < piles.size(); i++) {
                hr += (piles[i] + mid - 1) / mid; // Optimized ceil operation
            }
            
            if (hr <= h) {
                high = mid - 1; // Narrow search to the left (lower speeds)
            } else {
                low = mid + 1; // Narrow search to the right (higher speeds)
            }
        }
        
        return low;
    }
};
