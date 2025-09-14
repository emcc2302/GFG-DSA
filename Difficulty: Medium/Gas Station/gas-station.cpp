class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n=gas.size();
        int ans=0;
        int curr_gas=0;
        int total_gas = 0;
        int req_gas=0;
        
        for(int a:gas){
            total_gas+=a;
        }
        for(int b:cost){
            req_gas+=b;
        }
        if(total_gas<req_gas) return -1;
        else{
        
        for(int i=0;i<n;i++)
        {
       
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0){
                curr_gas=0;
                ans=i+1;
            }
        }
        }
      return ans;
    }
};