class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int len = s.length();
        string ret = "";
        for(int k=0; k<numRows; k++) {
            int leftSpan = 2*(numRows-1-k), rightSpan = 2*k;
            int curPos = k;
            while(curPos < len) {
                ret = ret + s[curPos];
                curPos += leftSpan;
                if(curPos >= len) break;
                if(leftSpan) ret = ret + s[curPos];
                if(!rightSpan) curPos += leftSpan;
                else curPos += rightSpan;
            }
        }
        return ret;
    }
};