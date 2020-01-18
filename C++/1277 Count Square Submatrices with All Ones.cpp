class Solution {
private:
    int prefix[1001][1001] = {0};
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                prefix[i+1][j+1] = prefix[i+1][j] + prefix[i][j+1] - prefix[i][j] + matrix[i][j];
        int cnt = 0;
        for(int x1=1; x1<=m; x1++)
            for(int x2=x1; x2<=m; x2++)
                for(int y1=1; y1<=n; y1++) {
                    int y2 = y1 + x2 - x1; // Square
                    cnt += (prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1])
                                == (y2 - y1 + 1) * (x2 - x1 + 1); 
                }
        return cnt;
    }
};