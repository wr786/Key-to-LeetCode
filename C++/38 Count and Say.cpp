class Solution {
public:
    string count_and_say(const string& str, int k) {
        if(k == 0) return str;
        int l = str.length();
        string nxtStr;
        int combo = 0;
        char cur;
        for(int i=0; i<l; i++) {
            if(str[i] == cur) {
                combo++;
            } else {
                if(combo != 0) {
                    nxtStr += combo + '0';
                    nxtStr += cur;
                }
                cur = str[i];
                combo = 1;
            }
        }
        if(combo) {
            nxtStr += combo + '0';
            nxtStr += cur;
        }
        return count_and_say(nxtStr, k-1);
    }
    string countAndSay(int n) {
        return count_and_say("1", n-1);
    }
};