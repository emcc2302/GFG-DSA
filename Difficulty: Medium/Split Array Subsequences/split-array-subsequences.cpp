#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        unordered_map<int, int> freq, need;

        for (int num : arr) freq[num]++;

        for (int num : arr) {
            if (freq[num] == 0) continue;

            if (need[num] > 0) {
                need[num]--;
                need[num + 1]++;
            } 

            else {
                bool canForm = true;
                for (int i = 0; i < k; i++) {
                    if (freq[num + i] <= 0) {
                        canForm = false;
                        break;
                    }
                }
                if (!canForm) return false;
                
                for (int i = 0; i < k; i++) freq[num + i]--;
                need[num + k]++;
                continue;
            }
            freq[num]--;
        }

        return true;
    }
};
