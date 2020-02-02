class Solution {
private:
    struct Cell {
        int val;
        int cnt;
    } cell[100001];
    int idx = 0;
    map<int, int> inCell;
    
    static bool cmp(Cell A, Cell B) {
        return A.cnt > B.cnt;
    }
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if(!inCell[arr[i]]) {
                cell[++idx].val = arr[i];
                inCell[arr[i]] = idx;
                cell[idx].cnt = 1;
            } else {
                cell[inCell[arr[i]]].cnt++;
            }
        }
        sort(cell+1, cell+1+idx, cmp);
        int retCnt = 0; n /= 2;
        for(int i=1; i<=idx; i++) {
            n -= cell[i].cnt;
            retCnt++;
            if(n <= 0) break; 
        }
        return retCnt;
    }
};