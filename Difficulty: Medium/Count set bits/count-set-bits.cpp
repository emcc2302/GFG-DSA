class Solution {
public:
    int countSetBits(int n) {
        if (n == 0) return 0;

        // Find largest power of 2 <= n
        int x = 0;
        while ((1 << (x + 1)) <= n) {
            x++;
        }

        int p = 1 << x; // 2^x

        // Formula application
        int bits_till_p_minus_1 = x * (p >> 1);
        int msb_bits = n - p + 1;
        int rest = n - p;

        return bits_till_p_minus_1 + msb_bits + countSetBits(rest);
    }
};
