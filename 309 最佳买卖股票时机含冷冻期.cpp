class Solution {
private:
    int dp[100001][3];
    // st0 : buy
    // st1 : sell
    // st2 : freeze or do nothing
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <= 1) return 0;
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i=1; i<len; i++) {
            dp[i][0] = dp[i-1][2];
            dp[i][2] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
            dp[i][1] = 0;
            for(int j=0; j<i; j++)
                dp[i][1] = max(dp[i][1], dp[j][0] + prices[i] - prices[j]);
        }
        return max(max(dp[len-1][0], dp[len-1][1]), dp[len-1][2]);
    }
};