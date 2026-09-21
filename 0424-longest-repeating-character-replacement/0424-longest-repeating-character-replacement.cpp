class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right;
        int maxi=0,n=s.size(),co=0;
        vector<int> count(26,0);
        for(right=0;right<n;right++){
            count[s[right]-'A']++;
            co=max(co,count[s[right]-'A']);
            if((right-left+1)-co>k){
                count[s[left]-'A']--;
                left++;
            }
            maxi=max(maxi,(right-left+1));
        }
        return maxi;

    }
};