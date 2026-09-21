class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       priority_queue<pair<int,int>> q;
       vector<int> ans;
       int n=nums.size(),i;
       if(k==1){
        return nums;
       }
       for(i=0;i<n;i++){
            q.push({nums[i],i});
            if(i>=k-1){
                while(q.top().second<=i-k){
                    q.pop();
                }
                ans.push_back(q.top().first);
            }
       }
       return ans;
    }
};