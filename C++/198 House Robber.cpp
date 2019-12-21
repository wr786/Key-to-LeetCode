// 执行用时 :0 ms, 在所有 cpp 提交中击败了100.00% 的用户
// 内存消耗 :8.6 MB, 在所有 cpp 提交中击败了81.12%的用户
int dp[10000][2];
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0; // for robustness
        for(int i=0; i<len; i++) {
            if(i > 0) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                dp[i][1] = dp[i-1][0] + nums[i];
            } else {
                dp[i][0] = 0;
                dp[i][1] = nums[i];
            }
        }
        return max(dp[len-1][0], dp[len-1][1]);
    }
};