class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long ans=0,n=s.size();
        long long num=0,sign=1;
        for(int i=0;i<n;i++){
            if(s[i]==' ')continue;
            if(s[i]>='0' && s[i]<='9'){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                ans=ans+sign*num;
                sign=1;
                num=0;
            }
            else if(s[i]=='-'){
                ans+=sign*num;
                sign=-1;
                num=0;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                sign=1;
                ans=0;
            }
            else{
                ans+=sign*num;
                num=0;
                ans*=st.top();
                st.pop();
                ans+=st.top();
                st.pop();
            }
        }
        ans+=sign*num;
        return (int)ans;
    }
};