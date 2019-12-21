class Solution {
private:
    int viscol[14] = {0};
    int visrdl[27] = {0}; // ↘↘
    int visldl[27] = {0}; // ↙↙
    int nGlobal;
    int ans = 0;
    void search(int pos) {
        if(pos == nGlobal + 1) {
            vector<string> thisAns;
            ans++;
            return;
        }
        for(int j=1; j<=nGlobal; j++) { // 第pos行，第i列 
            if(!viscol[j] && !visrdl[pos+j] && !visldl[nGlobal+1+pos-j]) {
                viscol[j] = visrdl[pos+j] = visldl[nGlobal+1+pos-j] = 1;
                search(pos+1);
                viscol[j] = visrdl[pos+j] = visldl[nGlobal+1+pos-j] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        nGlobal = n;
        search(1);
        return ans;
    }
};