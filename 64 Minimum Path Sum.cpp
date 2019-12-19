#define _i (i+1)
#define _j (j+1)
class Solution {
    int dp[1001][1001];
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); if(m <= 0) return 0;
        int n = grid[0].size(); if(n <= 0) return 0;
        for(int i=1; i<=m; i++) 
            for(int j=1; j<=n; j++)
                dp[i][j] = INT_MAX;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(i == 0) { // row 1
                    if(j == 0) dp[_i][_j] = grid[i][j]; // startPoint 
                    else dp[_i][_j] = dp[_i][j] + grid[i][j];
                } else if(j == 0) { // col 1
                    dp[_i][_j] = dp[i][_j] + grid[i][j];                    
                } else {
                    dp[_i][_j] = min(dp[_i][j], dp[i][_j]) + grid[i][j];
                }
            }
        return dp[m][n];
    }
};