class Solution {
private:
    int dp[10001][2]; // 滚动，去掉i状态等价
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(!n || !k) return 0;
        if(k > n/2) { // 相当于II，无限次交易
            int ans = 0;
            for(int i=0; i<n-1; i++)
                if(prices[i+1] > prices[i])
                    ans += prices[i+1] - prices[i];
            return ans;
        }
        dp[0][0] = 0;
        for(int i=1; i<=k; i++) dp[i][0] = -INT_MAX;
        for(int i=0; i<=k; i++) dp[i][1] = -INT_MAX;
        dp[1][1] = -prices[0];
        for(int i=1; i<n; i++) {
            for(int _k=0; _k<=k; _k++) {
                dp[_k][0] = max(dp[_k][0], dp[_k][1] + prices[i]);
                dp[_k][1] = dp[_k][1];
                if(_k) dp[_k][1] = max(dp[_k][1], dp[_k-1][0] - prices[i]);
            }
        }
        int ret = -INT_MAX;
        for(int i=0; i<=k; i++) ret = max(ret, dp[i][0]);
        return ret;
    }
};