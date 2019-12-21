class Solution {
private:
    int dp[10001][2]; 
    int ans = 0;
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0) return 0;
        if(len == 1) return nums[0];
        for(int round=0; round<2; round++) { // for diff cases
            // Round #1 : 0..n-1
            // Round #2 : 1..n
            dp[round][0] = 0, dp[round][1] = nums[round];
            for(int i=round+1; i<len-1+round; i++) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = dp[i-1][0] + nums[i];
            }
            ans = max(ans, dp[len+round-2][0]);
            ans = max(ans, dp[len+round-2][1]);
        }
        return ans;
    }
};