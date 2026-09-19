class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int i, j, k, n = nums.size();
        sort(nums.begin(), nums.end());
        for (i = 0; i < n-2; i++) {
            int sum = -nums[i];
            if((i>0 && nums[i]==nums[i-1])||(nums[i]>0))continue;
            j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] == sum) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k && nums[k]==nums[k-1])k--;
                    j++,k--;
                } else if (nums[j] + nums[k] < sum) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};