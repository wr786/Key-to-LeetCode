class Solution {
private:
    int dp[501][501];
    /*  将word1[1:m]转换为word2[1:n]最少操作数
        状态转移方程
        dp[m][n] = min  dp[m-1][n-1], word1[m] == word2[n]
                        dp[m][n-1] + 1, 删除一个字符
                        dp[m-1][n] + 1, 插入一个字符
                        dp[m-1][n-1] + 1, 替换一个字符
        边界条件
        dp[m][0] = m, dp[0][n] = n, dp[0][0] = 0

    */
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        for(int i=1; i<=l1; i++) {
            for(int j=1; j<=l2; j++) {
                dp[i][j] = 0x3f3f3f3f;
            }
        }
        for(int i=1; i<=l1; i++)
            dp[i][0] = i;
        for(int i=1; i<=l2; i++)
            dp[0][i] = i;
        dp[0][0] = 0;
        for(int i=1; i<=l1; i++) {
            for(int j=1; j<=l2; j++) {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        return dp[l1][l2];
    }
};