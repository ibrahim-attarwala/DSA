class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool> check(n+2,false);
        for(int i=0;i<n;i++){
            if(nums[i]>0 && nums[i]<=n){
                check[nums[i]]=true;
            }
        }
        for(int i=1;i<=n+1;i++){
            if(!check[i])return i;
        }
        return -1;
    }
};