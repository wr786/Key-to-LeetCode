class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector< vector<int> > dis = matrix;
        // 两次对角DP即可
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(matrix[i][j]) dis[i][j] = INT_MAX-1;
                else dis[i][j] = 0;
                if(j) dis[i][j] = min(dis[i][j-1]+1, dis[i][j]);
                if(i) dis[i][j] = min(dis[i-1][j]+1, dis[i][j]);
            }
        for(int i=m-1; i>=0; i--)
            for(int j=n-1; j>=0; j--) {
                if(j+1 < n) dis[i][j] = min(dis[i][j+1]+1, dis[i][j]);
                if(i+1 < m) dis[i][j] = min(dis[i+1][j]+1, dis[i][j]);
            }
        return dis;
    }
};