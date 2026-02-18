class Solution {
  public:
  
    long long merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long invCount = 0;
        
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                invCount += (mid - left + 1); 
                right++;
            }
        }
        
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        
        return invCount;
    }
    
    long long mergeSort(vector<int> &arr, int low, int high) {
        long long invCount = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            
            invCount += mergeSort(arr, low, mid);
            invCount += mergeSort(arr, mid + 1, high);
            invCount += merge(arr, low, mid, high);
        }
        return invCount;
    }
  
    int inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
