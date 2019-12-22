class Solution {
    int nGlobal, kGlobal;
    int vis[10001];
    vector<vector<int>> ans;
    void search(int pos, int last) {
        if(pos == kGlobal+1) {
            vector<int> thisAns;
            for(int i=1; i<=nGlobal; i++)
                if(vis[i]) thisAns.push_back(i);
            ans.push_back(thisAns);
            return;
        }
        for(int i=last+1; i<=nGlobal; i++) {
            vis[i] = 1;
            search(pos+1, i);
            vis[i] = 0;
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        nGlobal = n, kGlobal = k;
        search(1, 0);
        return ans;
    }
};