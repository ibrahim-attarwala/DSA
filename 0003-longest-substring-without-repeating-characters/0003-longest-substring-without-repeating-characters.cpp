class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> frequency(128,0);
        int n=s.size();
        int maxi=0,left=0;

        //variable sliding window in which I am making the window smaller if the rightmost element of the window is repeated 
        for(int right=0;right<n;right++){
            frequency[s[right]]++;
            while(frequency[s[right]]>1){
                    frequency[s[left]]--;
                    left++;
            }
            maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};