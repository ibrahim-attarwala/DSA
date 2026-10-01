class Solution {
public:
    int minQueenMoves(vector<int>& king, vector<int>& t) {
        if(king[0]==t[0] && king[1]==t[1])return 0;
        if(king[0]==t[0] || king[1]==t[1] || abs(king[0]-t[0])==abs(king[1]-t[1])){
            return 1;
        }
        return 2;
    }
};