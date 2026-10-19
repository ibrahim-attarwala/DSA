class Solution {
public:
    int lengthOfLastWord(string s) {
        int i;
        int n=s.size();
        int leng=0;
        while(n>0 && s[n-1]==' '){
            n--;
        }
        if(n==0){
            return 0;
        }
        for(i=0;i<n;i++){
            if(s[i]==' '){
                leng=0;
            }
            else{
                leng++;
            }
        }
        return leng;
    }
};