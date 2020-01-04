class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length(), lb = b.length();
        if(la < lb) {
            swap(a, b); 
            swap(la, lb);
        }
        int upDigit = 0;
        for(int i=1; i<=lb; i++) {
            a[la-i] = a[la-i]-'0' + b[lb-i]-'0' + upDigit;
            upDigit = a[la-i] / 2;
            a[la-i] %= 2;
            a[la-i] += '0';
        }
        while(la > lb) {
            lb++;
            a[la-lb] = a[la-lb]-'0' + upDigit;
            upDigit = a[la-lb] / 2;
            a[la-lb] %= 2;
            a[la-lb] += '0';
        }
        if(upDigit) a = '1' + a;
        return a;
    }
};