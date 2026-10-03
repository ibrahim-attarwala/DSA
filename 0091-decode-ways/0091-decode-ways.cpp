class Solution {
public:

    long long f(string s,int ind,int n,vector<int>& dp){
        if(ind==n){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(ind==n-1){
            return 1;
        }
        if(dp[ind]!=-1)return dp[ind];
        int take1=0,take2=0;
        if((s[ind]<'2')||(s[ind]=='2' && s[ind+1]<'7')){
            take2=f(s,ind+2,n,dp);
        }
        take1=f(s,ind+1,n,dp);
        return dp[ind]=take1+take2;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return f(s,0,s.size(),dp);
    }
};