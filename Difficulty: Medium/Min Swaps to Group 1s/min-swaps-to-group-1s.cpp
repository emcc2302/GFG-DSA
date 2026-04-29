class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
          int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                count++;
            }
        }
        int window=count;
        if(count==0){
            return -1;
        }
        if(count==n){
            return 0;
        }
        int maxi=INT_MAX;
        int count1=0;
        for(int i=0;i<window;i++){
            if(arr[i]==0){
                count1++;
            }
        }
        if(maxi>count1){
            maxi=count1;
        }
        int x=0;
        for(int j=window;j<n;j++){
            if(arr[x]==0){
                count1--;
            }
            if(arr[j]==0){
                count1++;
            }
            if(maxi>count1){
                maxi=count1;
            }
            x++;
        }
        return maxi;
    }
};