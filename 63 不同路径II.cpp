class Solution {
private:
    long long dp[101][101] = {0};
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m <= 0) return 1;
        int n = obstacleGrid[0].size();
        if(n <= 0) return 1;
        dp[1][1] = 1 - obstacleGrid[0][0];
        for(int _i=0; _i<m; _i++)
            for(int _j=0; _j<n; _j++) {
                int i = _i + 1, j = _j + 1;
                if(i==1 && j==1) continue;
                if(obstacleGrid[_i][_j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        return dp[m][n];
    }
};