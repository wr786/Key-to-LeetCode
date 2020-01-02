class Solution {
private:
    inline string powStr(string str, int times) { // 字符串快速幂
        if(times == 0) return "";
        if(times == 1) return str;
        string half = powStr(str, times/2);
        return (times % 2 ? half+half+str : half+half);
    }
public:
    string decodeString(string s) {
        int len = s.length();
        string ans; 
        for(int i=0; i<len; i++) {
            if(isdigit(s[i])) {
                int posLeft = s.find('[', i+1), posRight;
                int times = atoi(s.substr(i, posLeft-i).c_str());
                int leftCnt = 1, rightCnt = 0;
                i = posLeft;
                while(++i) {
                    if(s[i] == '[') leftCnt++;
                    else if(s[i] == ']') {
                        rightCnt++;
                        if(leftCnt == rightCnt) {
                            posRight = i;
                            break;
                        }
                    }
                }
                string str = decodeString(s.substr(posLeft+1, posRight-posLeft-1));
                ans += powStr(str, times);
                i = posRight;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};