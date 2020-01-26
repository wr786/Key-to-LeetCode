class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int m = haystack.length(), n = needle.length();
        int curPos = 0;
        for(int i=0; i<m; i++) {
            if(haystack[i] == needle[curPos]) {
                curPos++;
                if(curPos == n) return i - curPos + 1;
            } else {
                i = i - curPos;
                curPos = 0;
            }         
        }
        return -1;
    }
};