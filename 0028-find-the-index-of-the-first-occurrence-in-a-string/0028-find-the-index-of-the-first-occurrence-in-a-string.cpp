class Solution {
public:
    int strStr(string s, string t) {
        int n=s.size(),m=t.size();
        if(n<m)return -1;
        for(int i=0;i<=n-m;i++){
            if(s[i]==t[0]){
                bool ans=true;
                for(int j=0;j<m;j++){
                    if(s[i+j]!=t[j]){
                        ans=false;
                        break;
                    }
                }
                if(ans){
                    return i;
                }
            }
        }
        return -1;
    }
};