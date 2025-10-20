#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    // Pre-calculated Catalan numbers C0 to C6. 
    // Since arr.size() <= 6, the maximum subtree size is 5, so we need up to C5.
    // C0=1, C1=1, C2=2, C3=5, C4=14, C5=42, C6=132
    // We only need up to C5, as max(N_left, N_right) is at most 5.
    long long catalan[7] = {1, 1, 2, 5, 14, 42, 132}; 

    // An alternative (safer) way to calculate catalan numbers up to size n
    void precomputeCatalan(int n) {
        if (n >= 7) return; // Constraint max n is 6, so 7 is safe
        catalan[0] = 1;
        for (int i = 1; i <= n; ++i) {
            catalan[i] = 0;
            for (int j = 0; j < i; ++j) {
                catalan[i] += catalan[j] * catalan[i - 1 - j];
            }
        }
    }

public:
    /**
     * @brief Calculates the number of unique BSTs formed when arr[i] is chosen as the root.
     * * @param arr The input array of distinct elements.
     * @return vector<int> The array where the ith element is the count of BSTs with arr[i] as root.
     */
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
        // With n <= 6, the pre-calculated array is sufficient.
        // If n was larger, we would call precomputeCatalan(n-1);
        
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            int root_val = arr[i];
            int n_left = 0;
            int n_right = 0;

            // Count the elements smaller (left subtree) and larger (right subtree) than the root
            for (int j = 0; j < n; ++j) {
                if (i == j) continue; // Skip the root itself

                if (arr[j] < root_val) {
                    n_left++;
                } else { // arr[j] > root_val since elements are distinct
                    n_right++;
                }
            }
            
            // The number of unique BSTs with root_val as root is C(n_left) * C(n_right)
            // C(k) is the k-th Catalan number
            long long count = catalan[n_left] * catalan[n_right];
            
            // The problem specifies the return type as vector<int>, though 
            // the maximum value C5*C0 (42) fits well within an int.
            result.push_back((int)count); 
        }

        return result;
    }
};