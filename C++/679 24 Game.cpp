class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        return judgePoint24_4(a, b, c, d);
    }

    bool judgePoint24_4(double &a, double &b, double &c, double &d) {
        return judgePoint24_3(a + b, c, d) ||
               judgePoint24_3(a - b, c, d) ||
               judgePoint24_3(b - a, c, d) ||
               judgePoint24_3(a * b, c, d) ||
               judgePoint24_3(a / b, c, d) ||
               judgePoint24_3(b / a, c, d) ||
               judgePoint24_3(a + c, b, d) ||
               judgePoint24_3(a - c, b, d) ||
               judgePoint24_3(c - a, b, d) ||
               judgePoint24_3(a * c, b, d) ||
               judgePoint24_3(a / c, b, d) ||
               judgePoint24_3(c / a, b, d) ||
               judgePoint24_3(a + d, b, c) ||
               judgePoint24_3(a - d, b, c) ||
               judgePoint24_3(d - a, b, c) ||
               judgePoint24_3(a * d, b, c) ||
               judgePoint24_3(a / d, b, c) ||
               judgePoint24_3(d / a, b, c) ||
               judgePoint24_3(b + c, a, d) ||
               judgePoint24_3(b - c, a, d) ||
               judgePoint24_3(c - b, a, d) ||
               judgePoint24_3(b * c, a, d) ||
               judgePoint24_3(b / c, a, d) ||
               judgePoint24_3(c / b, a, d) ||
               judgePoint24_3(b + d, a, c) ||
               judgePoint24_3(b - d, a, c) ||
               judgePoint24_3(d - b, a, c) ||
               judgePoint24_3(b * d, a, c) ||
               judgePoint24_3(b / d, a, c) ||
               judgePoint24_3(d / b, a, c) ||
               judgePoint24_3(c + d, a, b) ||
               judgePoint24_3(c - d, a, b) ||
               judgePoint24_3(d - c, a, b) ||
               judgePoint24_3(c * d, a, b) ||
               judgePoint24_3(c / d, a, b) ||
               judgePoint24_3(d / c, a, b);
    }

    bool judgePoint24_3(double a, double &b, double &c) {
        return judgePoint24_2(a + b, c) ||
               judgePoint24_2(a - b, c) ||
               judgePoint24_2(b - a, c) ||
               judgePoint24_2(a * b, c) ||
               judgePoint24_2(a / b, c) ||
               judgePoint24_2(b / a, c) ||
               judgePoint24_2(a + c, b) ||
               judgePoint24_2(a - c, b) ||
               judgePoint24_2(c - a, b) ||
               judgePoint24_2(a * c, b) ||
               judgePoint24_2(a / c, b) ||
               judgePoint24_2(c / a, b) ||
               judgePoint24_2(b + c, a) ||
               judgePoint24_2(b - c, a) ||
               judgePoint24_2(c - b, a) ||
               judgePoint24_2(b * c, a) ||
               judgePoint24_2(b / c, a) ||
               judgePoint24_2(c / b, a);
    }

    bool judgePoint24_2(double a, double &b) {
        return judgePoint24_1(a + b) ||
               judgePoint24_1(a - b) ||
               judgePoint24_1(b - a) ||
               judgePoint24_1(a * b) ||
               judgePoint24_1(a / b) ||
               judgePoint24_1(b / a);
    }

    bool judgePoint24_1(double a) {
        return fabs(a - 24) < 1e-6;
    }
};