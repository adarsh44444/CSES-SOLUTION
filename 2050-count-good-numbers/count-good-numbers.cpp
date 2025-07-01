class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        if (exp == 0) return 1;
        long long half = power(base, exp / 2);
        long long result = (half * half) % MOD;
        if (exp % 2 == 1) result = (result * base) % MOD;
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2; // ceil(n/2)
        long long oddPos = n / 2;        // floor(n/2)

        long long evenWays = power(5, evenPos); // 5 options for even positions
        long long oddWays = power(4, oddPos);   // 4 options for odd positions

        return (evenWays * oddWays) % MOD;
    }
};
