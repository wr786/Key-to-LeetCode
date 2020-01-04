class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int temp = a ^ b;
            b = (unsigned int)(a & b) << 1; // 避免溢出
            a = temp;
        }
        return a;
    }
};