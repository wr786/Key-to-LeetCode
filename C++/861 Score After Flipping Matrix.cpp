class Solution {
private:
    int m, n;
    int xLazyTag[20] = {0}, yLazyTag[20] = {0};
public:
    int matrixScore(vector<vector<int>>& A) {
        m = A.size();
        if(m <= 0) return 0;
        n = A[0].size();
        // 第一列必全为1
        int cnt1 = 0;
        for(int i=0; i<m; i++) cnt1 += A[i][0];
        if(2 * cnt1 < m) yLazyTag[0] = 1;
        for(int i=0; i<m; i++)
            if(yLazyTag[0] ^ A[i][0] == 0) xLazyTag[i] = 1;
        // 因为首位数相同，所以后几列只需争取同列的1尽可能得多
        for(int j=1; j<n; j++) {
            cnt1 = 0;
            for(int i=0; i<m; i++) cnt1 += xLazyTag[i] ^ A[i][j];
            if(2 * cnt1 < m) yLazyTag[j] = 1;
        }
        // 计算得分
        int ret = 0, lineSum;
        for(int i=0; i<m; i++) {
            lineSum = 1; // 通过构造已经知道第一列都是1了
            for(int j=1; j<n; j++) {
                if(xLazyTag[i] + yLazyTag[j] == 1) {
                    lineSum = (lineSum<<1)|(1^A[i][j]);
                } else {
                    lineSum = (lineSum<<1)|A[i][j];
                }
            }
            ret += lineSum;
        }
        return ret;
    }
};