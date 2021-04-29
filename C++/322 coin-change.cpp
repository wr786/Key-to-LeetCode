class Solution {
private:
    int dp[13][10001]; 
    /*  dp[n][m] 表示用前n种钱至少要几个才能加到m
        状态转移方程：
        dp[n][m] = min(dp[n-1][m-k*v[n]] + k)
        边界条件：
        dp[0][0] = 0
    */
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        for(int i=0; i<=n; i++)
            for(int j=0; j<=amount; j++)
                dp[i][j] = 0x3f3f3f3f;
        dp[0][0] = 0;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=amount; j++) {
                dp[i][j] = dp[i-1][j];
                if(j >= coins[i-1])
                    dp[i][j] = min(dp[i][j], dp[i][j-coins[i-1]] + 1);
            }
        }
        return dp[n][amount] == 0x3f3f3f3f? -1: dp[n][amount];
    }
};