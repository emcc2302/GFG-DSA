class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // Sort both arrays
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());

        int n = mices.size();
        int ans = 0;

        // Match ith mouse with ith hole
        for (int i = 0; i < n; i++) {
            ans = max(ans, abs(mices[i] - holes[i]));
        }

        return ans;
    }
};
