class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int sum=1,i,n=nums.size();
        reverse(nums.begin(),nums.end());
        for(i=0;i<n;i++){
            sum=sum+nums[i];
            nums[i]=sum%10;
            sum/=10;
        }
        if(sum!=0){
            nums.push_back(sum);
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};