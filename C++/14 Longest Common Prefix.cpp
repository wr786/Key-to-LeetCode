class Solution {
private:
    static inline bool cmp(string A, string B) {
        return A.length() < B.length();
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix;
        char curPrefix;
        int n = strs.size();
        if(n == 0) return commonPrefix;
        sort(strs.begin(), strs.end(), cmp);
        int minLength = strs[0].length();
        for(int curpos = 0; curpos < minLength; curpos++) {
            curPrefix = strs[0][curpos];
            bool flag = true;
            for(int i=1; i<n; i++) {
                if(strs[i][curpos] != curPrefix) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            commonPrefix = commonPrefix + curPrefix;
        }
        return commonPrefix;
    }
};