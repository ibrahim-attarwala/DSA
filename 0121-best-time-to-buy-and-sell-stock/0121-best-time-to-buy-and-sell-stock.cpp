class Solution {
public:
    int maxProfit(vector<int>& v) {
        int i,n=v.size();
        int mini=v[0],maxi=v[0];
        int ans=0;
        for(i=0;i<n;i++){
            mini=min(mini,v[i]);
            maxi=max(mini,v[i]);
            ans=max(ans,maxi-mini);
        }
        return ans;
    }
};