class Solution {
public:
    int myAtoi(string str) {
        long long ret = 0;
        int sgn = 1, n = str.length();
        bool flag = false;
        for(int i=0; i<n; i++) {
            if(flag) { // 减少判断次数
                if(!isdigit(str[i])) break;
                ret = ret * (long long)10 + str[i] - '0';
                if(sgn*ret > (long long)INT_MAX) return INT_MAX; // 提前终止
                else if(sgn*ret < (long long)INT_MIN) return INT_MIN;
            } else if(str[i] == ' ') continue;
            else if(str[i] == '-') {sgn *= -1; flag = true;}
            else if(str[i] == '+') {flag = true;}
            else if(!isdigit(str[i])) break;
            else {
                flag = true;
                ret = ret * (long long)10 + str[i] - '0';
            }
        }
        ret = ret * (long long)sgn;
        return ret;
    }
};