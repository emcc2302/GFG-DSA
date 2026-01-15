class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        // Step 1: Give each child at least 1 candy
        vector<int> candies(n, 1);

        // Step 2: Left-to-right pass
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right-to-left pass
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum up the minimum required candies
        long long total = 0;
        for (int count : candies) {
            total += count;
        }
        return (int)total;
    }
};
