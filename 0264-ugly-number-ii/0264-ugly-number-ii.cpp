class Solution {
public:
    int nthUglyNumber(int n) {
        int p2=0,p3=0,p5=0;
        vector<int> ugly(n,1);
        for(int i=1;i<n;i++){
            int n2=ugly[p2]*2;
            int n3=ugly[p3]*3;
            int n5=ugly[p5]*5;

            int next=min({n2,n3,n5});
            ugly[i]=next;

            if(next==n2)p2++;
            if(next==n3)p3++;
            if(next==n5)p5++;
        }
        return ugly[n-1];
    }
};