class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0, j = n - 1;

        // Step 1: Find candidate
        while (i < j) {
            if (mat[i][j] == 1) {
                // i knows j → i can't be celebrity
                i++;
            } else {
                // i doesn't know j → j can't be celebrity
                j--;
            }
        }
        
        int cand = i;

        // Step 2: Verify candidate
        for (int k = 0; k < n; k++) {
            if (k == cand) continue;
            // Celebrity should not know k
            if (mat[cand][k] == 1) return -1;
            // Everyone should know celebrity
            if (mat[k][cand] == 0) return -1;
        }

        return cand;
    }
};
