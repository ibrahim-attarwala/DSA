class Solution {
public:
    int trap(vector<int>& h) {
      int low=0,high=h.size()-1;
      int left=0,right=0,total=0;
      while(low<high){
        if(h[low]<=h[high]){
            if(h[low]<left){
                total+=(left-h[low]);
            }
            else{
                left=h[low];
            }
            low++;
        }
        else{
            if(h[high]<right){
                total+=(right-h[high]);
            }
            else{
                right=h[high];
            }
            high--;
        }
      }  
      return total;
    }
};