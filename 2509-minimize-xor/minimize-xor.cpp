class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;

        // Count the number of 1's in num2
        while (num2) {
            cnt += (num2 & 1);
            num2 >>= 1;
        }

        int result = 0;

        // Use the most significant bits of num1 to set bits in result
        for (int i = 31; i >= 0 && cnt > 0; i--) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                cnt--;
            }
        }

        // If there are still bits to set, set the least significant bits
        for (int i = 0; i <= 31 && cnt > 0; i++) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                cnt--;
            }
        }

        return result;
    }
};
