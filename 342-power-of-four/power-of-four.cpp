class Solution {
public:
    bool isPowerOfFour(int n) {
        long long n1=n;
        if((n1&(n1-1))==0&&(n1-1)%3==0) return 1;
        return 0;
    }
};