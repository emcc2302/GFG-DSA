class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        // ants moving left: time = position
        for(int x : left) ans = max(ans, x);

        // ants moving right: time = n - position
        for(int x : right) ans = max(ans, n - x);

        return ans;
    }
};
