class Solution {
public:
    int maximum69Number (int num) {
        int *d = new int[6];
        d[1] = num / 10000;
        d[2] = (num/1000) % 10;
        d[3] = (num/100) % 10;
        d[4] = (num/10) % 10;
        d[5] = num % 10;
        int start;
        for(start=1; start<=5; start++) {
            if(d[start] != 0) break;
        }
        int ret = 0; bool flag = true;
        for(int i=start; i<=5; i++) {
            if(flag) {
                if(d[i] == 6) {
                    flag = false;
                    d[i] = 9;
                }
            }
            ret = ret * 10 + d[i];
        }
        return ret;
    }
};