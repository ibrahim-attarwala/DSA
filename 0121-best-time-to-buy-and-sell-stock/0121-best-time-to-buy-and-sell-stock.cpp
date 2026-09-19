class Solution {
public:
    int maxProfit(vector<int>& v) {
        int i,n=v.size();
        vector<int> suff(n,0);
        vector<int> pre(n,0);
        pre[0]=v[0];
        for(i=1;i<n;i++){
            pre[i]=min(pre[i-1],v[i]);
        }
        suff[n-1]=v[n-1];
        for(i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],v[i]);
        }
        int ans=0;
        for(i=0;i<n;i++){
            ans=max(ans,suff[i]-pre[i]);
        }
        return ans;
    }
};