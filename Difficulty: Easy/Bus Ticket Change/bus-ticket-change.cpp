class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int cnt5 = 0, cnt10 = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 5){
                cnt5++;
            } 
            else if(arr[i] == 10){
               if (cnt5 == 0) return false;
                cnt5--;
                cnt10++;
            }
            else{
                if (cnt10 > 0 && cnt5 > 0) {
                    cnt10--;
                    cnt5--;
                } else if (cnt5 >= 3) {
                    cnt5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};