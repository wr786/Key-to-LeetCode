class Solution {
private:
    int dp[201];
    /* 滚动数组
        表达到<当前行>第n列时的最小路径
        状态转移方程：
        dp[i] = min(dp[i-1], dp[i]) + triangle[当前行-1][i-1]
        边界条件：
        dp[1] = triangle[0][0]
    */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=0; i<=n; i++)
            dp[i] = 0x3f3f3f3f;
        dp[1] = triangle[0][0];
        for(int i=2; i<=n; i++) {
            for(int j=i; j; j--) {
                dp[j] = min(dp[j-1], dp[j]) + triangle[i-1][j-1];
            }
        }
        int ret = 0x3f3f3f3f;
        for(int j=1; j<=n; j++)
            ret = min(ret, dp[j]);
        return ret;
    }
};