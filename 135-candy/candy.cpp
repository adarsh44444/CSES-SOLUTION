class Solution {
public:
#define ll long long
    int candy(vector<int>& ratings) {
        ll sum = 1;
        ll i = 1;
        ll n = ratings.size();

        while (i < n) {
            // Equal ratings
            while (i < n && ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
            }

            // Increasing slope
            ll peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1;
                sum += peak;
                i++;
            }

            // Decreasing slope
            ll down = 0;
            ll temp = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                down += 1;
                sum += down;
                i++;
            }

            // Adjust for peak if needed
            if (down >= peak) {
                sum += (down - peak + 1);
            }
        }

        return sum;
    }
};
