class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        
        if(n < 3) return {};
        
        vector<int> smaller(n), greater(n);
        
        // smaller array
        smaller[0] = -1;
        int min_idx = 0;
        
        for(int i = 1; i < n; i++){
            if(arr[min_idx] >= arr[i]){
                min_idx = i;
                smaller[i] = -1;
            }
            else{
                smaller[i] = min_idx;
            }
        }
        
        // greater array
        greater[n-1] = -1;
        int max_idx = n-1;
        
        for(int i = n-2; i >= 0; i--){
            if(arr[max_idx] <= arr[i]){
                max_idx = i;
                greater[i] = -1;
            }
            else{
                greater[i] = max_idx;
            }
        }
        
        
        for(int i = 0; i < n; i++){
            if(smaller[i] != -1 && greater[i] != -1){
                return {arr[smaller[i]], arr[i], arr[greater[i]]};
            }
        }
        
        return {};
    }
};