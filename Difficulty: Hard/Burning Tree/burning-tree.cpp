class Solution {
  public:
  int Burn(Node* root,int &timer,int target){
      if(!root)
      return 0;
      //returning minus value to identify the burn
      if(root->data==target)
      return -1;
      //left part se
      int left= Burn(root->left,timer,target);
      int right= Burn(root->right,timer,target);
      //left wala 0 se chota mtlb agg wahi se aaraha hai
      if(left<0){
          timer=max(timer,abs(left)+right);
          return left-1;
      }
       //right wala 0 se chota mtlb agg wahi se aaraha hai
      if(right<0){
          timer=max(timer,abs(right)+left);
          return right-1;
      }
      // dono part me kahi aag na laga ho to height dege
      return 1+max(left,right);
  }
  // find wala function buning node ko find karne ke liya
  void find(Node* root,int target,Node *&BurnNode){
      if(!root)
      return;
      if(root->data==target){
          BurnNode=root;
          return;
      }
      //left
      find(root->left,target,BurnNode);
      //right
      find(root->right,target,BurnNode);
  }
  // height wala function burn node ka height find kar ne ke liya
  int Height(Node *root){
      if(!root)
      return 0;
      return 1+max(Height(root->left),Height(root->right));
  }
    int minTime(Node* root, int target) {
        // code here
        int timer=0;
        Burn(root,timer,target);
        //height of target node jisme agg lagai hai
        Node *BurnNode=NULL;
        find(root,target,BurnNode);
        int high=Height(BurnNode)-1;
        return max(timer,high);
        
    }
};

