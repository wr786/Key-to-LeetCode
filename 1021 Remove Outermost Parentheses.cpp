class Solution {
public:
    string removeOuterParentheses(string S) {
        int len = S.length();
        if(len <= 2) return "";
        string ret = "";
        int leftCrakets = 0, rightCrakets = 0, lastLeftCraketIdx = 0;
        for(int i=0; i<len; i++) {
            if(S[i] == '(') {if(leftCrakets++ == 0) lastLeftCraketIdx = i;}
            else if(S[i] == ')') {
                rightCrakets++;
                if(leftCrakets == rightCrakets) {
                    ret = ret + S.substr(lastLeftCraketIdx+1, i-lastLeftCraketIdx-1);
                    leftCrakets = rightCrakets = 0;
                }
            }
        }
        return ret;
    }
};