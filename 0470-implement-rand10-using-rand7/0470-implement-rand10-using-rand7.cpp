// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int idx;
        do{
            int r=rand7();
            int c=rand7();
            idx=(r-1)*7+c;
        }
        while(idx>40);
        return 1+(idx-1)%10;
    }
};