class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r;
        int sum=0,mini=INT_MAX;
        for(r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                mini=min(mini,(r-l+1));
                sum-=nums[l++];
            }
            
        }
        return mini==INT_MAX?0:mini;
    }
};