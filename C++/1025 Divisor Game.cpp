class Solution {
private:
    int dp[1001] = {0}; // if can win when left i
public:
    bool divisorGame(int N) {
        dp[0] = 0; dp[1] = 0; dp[2] = 1; dp[3] = 0;
        for(int i=4; i<=N; i++) {
            for(int j=1; j<i; j++) {
                if(i % j == 0) {
                    dp[i] = max(dp[i], 1 - dp[i-j]); // minimax
                }
            }
        }
        return dp[N] > 0;
    }
};