#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximizeMedian(vector<int>& arr, long long k) {
        int n = arr.size();
        int cur = (n - 1) / 2;  // median index
        sort(arr.begin(), arr.end());
        
        if (n % 2 == 0 && arr[cur + 1] - arr[cur] >= k) 
            return (arr[cur + 1] + arr[cur] + k) / 2;
        
        int len = 1;
        while (k) {
            while (cur < n - 1 && arr[cur] == arr[cur + 1]) {
                cur++;
                len++;
            }
            
            if (cur == n - 1)  
                return arr[cur] + k / len;
            
            long long diff = arr[cur + 1] - arr[cur];
            
            if (k >= diff * len) {
                k -= diff * len;
                cur++;
                len++;
            } else {
                return arr[cur] + k / len;
            }
        }
        
        return arr[cur];
    }
};
