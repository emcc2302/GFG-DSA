class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int getCount(int n, int d) {
        int lo = 1, hi = n;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long val = (long long)mid - digitSum(mid);

            if (val >= d) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if (ans == -1) return 0;
        return n - ans + 1;
    }
};
