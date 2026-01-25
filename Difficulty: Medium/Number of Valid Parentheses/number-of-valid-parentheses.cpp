class Solution {
  public:
  long long fact(int x) {
        if (x <= 1) return 1;
        return (long long)x * fact(x - 1);
    }
    
    int findWays(int n) {
        if (n % 2 != 0) return 0;
        long long ans = fact(n) / (fact(n/2 + 1) * fact(n/2));
        return (int)ans;
    }
};