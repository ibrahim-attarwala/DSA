class Solution {
public:
    void start(vector<string> &ans,string s,int open,int close,int n){
        if(s.size()==n*2){
            ans.push_back(s);
            return;
        }
        if(open<n){
            start(ans,s+"(",open+1,close,n);
        }
        if(close<open){
            start(ans,s+")",open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        start(res,"",0,0,n);
        return res;
    }
};