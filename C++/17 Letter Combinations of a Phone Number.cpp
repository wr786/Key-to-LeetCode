/*
	执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
	内存消耗 :8.6 MB, 在所有 cpp 提交中击败了51.58%的用户
*/
class Solution {
private:
    string digitsGlobal;
    int len;
    vector<string> ans;
    string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void search(int pos, string curStr) {
        if(pos == len) {
            ans.push_back(curStr);
            return;
        }
        int curLen = dict[digitsGlobal[pos] - '0'].length();
        for(int i=0; i<curLen; i++)
            search(pos+1, curStr+dict[digitsGlobal[pos] - '0'][i]);
    }
public:
    vector<string> letterCombinations(string digits) {
        digitsGlobal = digits;
        len = digits.length();
        if(len != 0) search(0, "");
        return ans;   
    }
};