class Solution {
private:
    int dp[50001][3]; // 0=>no stock 1=>have stock
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp[0][0] = 0, dp[0][1] = -prices[0] - fee, dp[0][2] = -INT_MAX;
        for(int i=1; i<n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i][0] - prices[i] - fee);
        }
        return dp[n-1][0];
    }
};