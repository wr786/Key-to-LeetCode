/*
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
内存消耗 :8.1 MB, 在所有 cpp 提交中击败了96.30%的用户
*/
class Solution {
private:
    int str2int(string str) {
        int len = str.length();
        int startPos = 0;
        int ret = 0, sign = 1;
        if(str[0] == '-') sign = -1, startPos = 1;
        for(int i=startPos; i<len; i++)
            if(str[i] != 'i')
                ret = ret * 10 + str[i] - '0';
        return sign * ret;
    }

    string int2str(int num) {
        if(num == 0) return "0";
        string ret; bool negFlag = false;
        if(num < 0) negFlag = true, num = -num;
        while(num) {
            ret = (char)(num % 10 + '0') + ret;
            num /= 10;
        }
        if(negFlag) ret = "-" + ret;
        return ret;
    }
public:
    string complexNumberMultiply(string a, string b) {
        int k1R, k1I, k2R, k2I;
        int dividePos = a.find('+');
        k1R = str2int(a.substr(0, dividePos));
        k1I = str2int(a.substr(dividePos+1));
        dividePos = b.find('+');
        k2R = str2int(b.substr(0, dividePos));
        k2I = str2int(b.substr(dividePos+1));
        int k3R = k1R * k2R - k1I * k2I;
        int k3I = k1R * k2I + k1I * k2R;
        return int2str(k3R) + "+" + int2str(k3I) + "i";
    }
};