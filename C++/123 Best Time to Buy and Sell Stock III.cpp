class Solution {
private:
    int dp[3][2]; // 滚动，去掉状态i
    // buytimes
    // 0=>with no stock, 1=>with stock
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        dp[0][0] = 0; dp[1][0] = dp[2][0] = -INT_MAX;
        dp[0][1] = -INT_MAX; dp[1][1] = -prices[0], dp[2][1] = -INT_MAX;
        for(int i=1; i<n; i++)
            for(int k=0; k<=2; k++) {
                dp[k][0] = max(dp[k][0], dp[k][1] + prices[i]);
                dp[k][1] = dp[k][1];
                if(k) dp[k][1] = max(dp[k][1], dp[k-1][0] - prices[i]);
            }
        return max(max(dp[0][0], dp[1][0]), dp[2][0]);
    }
};