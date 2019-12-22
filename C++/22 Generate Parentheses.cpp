class Solution {
private:
    vector<string> ans;
    int nGlobal;
    void search(int pos, int left, int right, string curStr) {
        if(pos == 2 * nGlobal + 1) {
            ans.push_back(curStr);
            return;
        }
        if(left < nGlobal)
            search(pos+1, left+1, right, curStr + '(');
        if(left > right)
            search(pos+1, left, right+1, curStr + ')');
    }
public:
    vector<string> generateParenthesis(int n) {
        nGlobal = n;
        search(1,0,0,"");
        return ans;
    }
};