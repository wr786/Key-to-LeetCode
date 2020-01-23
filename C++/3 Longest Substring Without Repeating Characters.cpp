class Solution {
private:
    map<char, int> dict;
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), ans = 0;
        int cnt = 0, left = 0;
        for(int i=0; i<n; i++) {
            if(!dict[s[i]]) {
                dict[s[i]] = i+1;
            } else {
                for(int j=left; j<dict[s[i]]-1; j++)
                    dict[s[j]] = 0;
                ans = max(ans, i - left);
                left = dict[s[i]];
                dict[s[i]] = i+1;
            }
            if(i == n-1)
                ans = max(ans, n - left);
        }
        return ans;
    }
};