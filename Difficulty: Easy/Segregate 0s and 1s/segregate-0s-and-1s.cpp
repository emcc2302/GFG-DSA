class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int countZero = 0;
        for (auto i : arr) {
            if (!i) {
               countZero++; 
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (countZero) {
                arr[i] = 0;
                countZero--;
            } else {
                arr[i] = 1;
            }
        }
    }
};