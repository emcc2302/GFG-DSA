
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
    
       int count0=0;
        int count1=0;
         int count2=0;
       for(int i=0;i<n;i++){
           if(arr[i]==0)  count0++;
           else if(arr[i]==1)  count1++;
           else  count2++;
       }
       int idx = 0;
       for(int i=0;i<count0;i++){
           arr[idx++]=0;

       }
        for(int i=0;i<count1;i++){
           arr[idx++]=1;
           
       }
        for(int i=0;i<count2;i++){
           arr[idx++]=2;
           
       }
      
    }
};

