#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
    long long catalan[7] = {1, 1, 2, 5, 14, 42, 132}; 
    void precomputeCatalan(int n) {
        if (n >= 7) return; 
        catalan[0] = 1;
        for (int i = 1; i <= n; ++i) {
            catalan[i] = 0;
            for (int j = 0; j < i; ++j) {
                catalan[i] += catalan[j] * catalan[i - 1 - j];
            }
        }
    }

public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
    
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            int root_val = arr[i];
            int n_left = 0;
            int n_right = 0;

            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                if (arr[j] < root_val) {
                    n_left++;
                } else { 
                    n_right++;
                }
            }
        
            long long count = catalan[n_left] * catalan[n_right];
            result.push_back((int)count); 
        }

        return result;
    }
};