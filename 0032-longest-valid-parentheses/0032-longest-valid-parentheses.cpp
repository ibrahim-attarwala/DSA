class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),l=0,r=0;
        int c1=0,c2=0;
        int ans=0;
        while(r<n){
            if(s[r]=='('){
                c1++;
            }
            else{
                c2++;
            }
            if(c1==c2){
                ans=max(ans,r-l+1);
            }
            else if(c1<c2){
                c1=0,c2=0;
                l=r+1;
            }
            r++;
        }
        c1=0,c2=0;
        r=n-1,l=n-1;
        while(l>=0){
            if(s[l]=='('){
                c1++;
            }
            else{
                c2++;
            }
            if(c1==c2){
                ans=max(ans,r-l+1);
            }
            else if(c1>c2){
                c1=0,c2=0;
                r=l-1;
            }
            l--;
        }
        return ans;
    }
};