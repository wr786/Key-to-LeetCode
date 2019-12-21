class Solution {
private:
    int chess[14][14] = {0};
    int viscol[14] = {0};
    int visrdl[27] = {0}; // ↘↘
    int visldl[27] = {0}; // ↙↙
    int nGlobal;
    vector<vector<string>> ans;
    void search(int pos) {
        if(pos == nGlobal + 1) {
            vector<string> thisAns;
            for(int i=1; i<=nGlobal; i++) {
                string thisRow;
                for(int j=1; j<=nGlobal; j++) {
                    if(chess[i][j]) thisRow += 'Q';
                    else thisRow += '.';
                }
                thisAns.push_back(thisRow);
            }
            ans.push_back(thisAns);
            return;
        }
        for(int j=1; j<=nGlobal; j++) { // 第pos行，第i列 
            if(!viscol[j] && !visrdl[pos+j] && !visldl[nGlobal+1+pos-j]) {
                chess[pos][j] = viscol[j] = visrdl[pos+j] = visldl[nGlobal+1+pos-j] = 1;
                search(pos+1);
                chess[pos][j] = viscol[j] = visrdl[pos+j] = visldl[nGlobal+1+pos-j] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        nGlobal = n;
        search(1);
        return ans;
    }
};