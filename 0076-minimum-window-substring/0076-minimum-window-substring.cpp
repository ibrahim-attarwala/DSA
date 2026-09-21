class Solution {
public:
    string minWindow(string s, string t) {
        int cnt=t.size(),mini=INT_MAX;
        int l=0,r=0;
        vector<int> m(128,0);
        for(int i=0;i<cnt;i++){
            m[t[i]]++;
        }
        int i=0;
        for(r=0;r<s.size();r++){
            if(m[s[r]]>0)cnt--;
            m[s[r]]--;
            while(cnt==0){
                if(r-l+1<mini)i=l;
                mini=min(mini,(r-l+1));
                if(m[s[l]]==0) cnt++;
                m[s[l]]++;
                l++;
            }
        }
        return (mini==INT_MAX?"":s.substr(i,mini));
    }
};