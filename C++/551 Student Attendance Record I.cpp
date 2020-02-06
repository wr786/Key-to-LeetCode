class Solution {
public:
    bool checkRecord(string s) {
        int Acnt = 0;
        int Lcombo = 0;
        int n = s.length();
        for(int i=0; i<n; i++) {
            if(s[i] == 'A') {
                Acnt++;
                if(Acnt > 1) return false;
                Lcombo = 0;
            } else if(s[i] == 'L') {
                Lcombo++;
                if(Lcombo > 2) return false;
            } else Lcombo = 0;
        }
        return true;
    }
};