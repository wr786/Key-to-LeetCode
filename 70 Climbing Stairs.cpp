class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int lower1 = 2, lower2 = 1, cur;
        for(int i=3; i<=n; i++) {
            cur = lower1 + lower2;
            lower2 = lower1;
            lower1 = cur;
        }
        return cur;
    }
};