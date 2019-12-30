class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int idx = 0, jdx = 0, iStar = -1, jStar = -1;
        while(idx < m) {
            if(jdx < n && (s[idx] == p[jdx]) || p[jdx] == '?') {
                idx++, jdx++;
            } else if(jdx < n && p[jdx] == '*') {
                iStar = idx;
                jStar = jdx++; // 类似KMP?
            } else if(iStar >= 0) {
                idx = ++iStar;
                jdx = jStar + 1;
            } else {
                return false;
            }
        }
        while(jdx < n && p[jdx] == '*') jdx++;
        return jdx == n;
    }
};