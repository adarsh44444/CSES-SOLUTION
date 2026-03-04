class Solution {
public:
    int minCost(int n) {
        long long ans=0;
        ans+=(n*(n+1))/2-n;
        return ans;
    }
};