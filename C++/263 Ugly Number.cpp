class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num && num % 2 == 0) num /= 2;
        while(num && num % 3 == 0) num /= 3;
        while(num && num % 5 == 0) num /= 5;
        return (num == 1);
    }
};