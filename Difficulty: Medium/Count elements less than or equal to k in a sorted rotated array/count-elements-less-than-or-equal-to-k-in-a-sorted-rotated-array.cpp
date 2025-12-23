class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        
        // Step 1: find pivot (index of minimum element)
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = low;

        // Step 2: count elements <= x in both sorted halves
        int count = 0;

        // left part: 0 to pivot-1
        if (pivot > 0) {
            count += upper_bound(arr.begin(), arr.begin() + pivot, x) 
                     - arr.begin();
        }

        // right part: pivot to n-1
        count += upper_bound(arr.begin() + pivot, arr.end(), x) 
                 - (arr.begin() + pivot);

        return count;
    }
};
