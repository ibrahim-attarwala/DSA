class Solution {
public:
    long long shadowPairs(vector<int>& v) {
        long long ans=0;
        int sum=0,r,n=v.size();
        stack<pair<int,long long>> st;
        for(r=0;r<n;r++){
            while(!st.empty() && st.top().first>v[r]){
                sum-=st.top().second;
                st.pop();
            }
            if(!st.empty() && st.top().first==v[r]){
                ans+=(sum-st.top().second);
                sum++;
                int t=st.top().second+1;
                st.pop();
                st.push({v[r],t});
            }
            else{
                ans+=(sum);
                st.push({v[r],1});
                sum++;
                
            }
        }
        return ans;
    }
};