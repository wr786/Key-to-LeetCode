class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens = s.length(), lent = t.length();
        int cur = 0;
        for(int i=0; i<lent; i++) {
            if(s[cur] == t[i]) cur++;
            if(cur == lens) break;
        }
        if(cur == lens) return true;
        else return false;
    }
};