class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int k = m + n - 1; // 对角线数目
        vector<int> djx[200];
        // 行
        for(int x=m-1; x>=0; x--) { // 自底向上
            int curx = x, cury = 0, cnt=0;
            while(curx < m && cury < n) {
                djx[x].push_back(mat[curx][cury]);
                curx++;cury++;cnt++;
            }
            sort(djx[x].begin(), djx[x].end());
            while(curx > 0 && cury > 0) {
                curx--; cury--;
                mat[curx][cury] = djx[x][--cnt];
            }
        }
        // 列
        for(int y=0; y<n; y++) { // 从左向右
            int curx = 0, cury = y, cnt = 0;
            while(curx < m && cury < n) {
                djx[m + y].push_back(mat[curx][cury]);
                curx++;cury++;cnt++;
            }
            sort(djx[m+y].begin(), djx[m+y].end());
            while(curx > 0 && cury > 0) {
                curx--; cury--;
                mat[curx][cury] = djx[m+y][--cnt];
            }
        }
        return mat;
    }
};