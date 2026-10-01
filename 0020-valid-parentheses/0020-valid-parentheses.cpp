class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i,n=s.size();
        for(i=0;i<n;i++){
            if(s[i]=='(' ||s[i]=='[' ||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(st.top()=='('){
                    if(s[i]!=')'){
                        return false;
                    }
                    st.pop();
                }
                else if(st.top()=='{'){
                    if(s[i]!='}')return false;
                    st.pop();
                }
                else if(st.top()=='['){
                    if(s[i]!=']')return false;
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};