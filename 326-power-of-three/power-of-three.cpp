class Solution {
public:
    bool isPowerOfThree(int n) {
        long long temp=pow(3,19);
        return n>0&&temp%n==0;
    }
};