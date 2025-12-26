class Solution {
  private:
    int countLessEqual(int target, vector<vector<int>>& mat) {
        int n = mat.size();
        int cnt = 0;
        int row = 0, col = n - 1;

        while (row < n && col >= 0) {
            if (mat[row][col] <= target) {
                cnt += (col + 1);
                row++;
            }
            else
                col--;
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int l = mat[0][0];
        int r = mat[n - 1][n - 1];

        while (l <= r) {
            int mid = l+(r-l)/2;
            int cnt = countLessEqual(mid, mat);
            if (cnt < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};