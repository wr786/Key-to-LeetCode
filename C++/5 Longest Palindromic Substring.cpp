class Solution {
private:
    bool dp[1000][1000]; // 记录[i:j]的一段是否为回文数
public:
    string longestPalindrome(string s) {
        int n = s.length();
        for(int i=0; i<n; i++) dp[i][i] = true; // span = 1
        for(int i=0; i<n-1; i++) dp[i][i+1] = (s[i]==s[i+1]); // span = 2
        for(int span=3; span<=n; span++)
            for(int startpos=0; startpos<n; startpos++) {
                if(startpos + span > n) break;
                dp[startpos][startpos+span-1] = dp[startpos+1][startpos+span-2] && (s[startpos]==s[startpos+span-1]);
            }
        for(int span=n; span; span--) 
            for(int startpos=0; startpos<n; startpos++) {
                if(startpos + span > n) break;
                if(dp[startpos][startpos+span-1]) return s.substr(startpos, span);
            }
        return "";
    }
};