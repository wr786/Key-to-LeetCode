class Solution {
private:
    int dp[59];
public:
    int integerBreak(int n) {
        dp[2] = 1;
        for(int i=3; i<=n; i++) {
            for(int j=0; j<i; j++) {
                int mul1 = max(j, dp[j]); // 不一定要拆i，留着i可能更好
                int mul2 = max(i-j, dp[i-j]);
                dp[i] = max(dp[i], mul1 * mul2);
            }
        }        
        return dp[n];
    }
};