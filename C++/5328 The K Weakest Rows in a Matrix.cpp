class Solution {
private:
    struct row{
        int idx;
        int cnt;
    };
public:
    static bool cmp(row A, row B) {
        if(A.cnt != B.cnt) return A.cnt < B.cnt;
        else return A.idx < B.idx;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<row> matIdx;
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++) {
            row curRow; curRow.cnt = 0; curRow.idx = i;
            matIdx.push_back(curRow);
            for(int j=0; j<n; j++) {
                if(mat[i][j]) matIdx[i].cnt++;
                else break;
            }
        }
        sort(matIdx.begin(), matIdx.end(), cmp);
        vector<int> ret;
        for(int i=0; i<k; i++)
            ret.push_back(matIdx[i].idx);
        return ret;
    }
};