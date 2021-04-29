class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        int l1 = text1.length(), l2 = text2.length();
        for(int i=0; i<=l1; i++)
            for(int j=0; j<=l2; j++) {
                dp[i][j] = 0;   // init
            }
        for(int i=1; i<=l1; i++)
            for(int j=1; j<=l2; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        return dp[l1][l2];
    }
};