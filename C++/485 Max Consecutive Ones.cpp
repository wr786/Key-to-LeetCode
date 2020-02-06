class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, n = nums.size(), ans = 0;
        for(int i=0; i<n; i++)
            if(nums[i]) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        return max(ans, cnt);
    }
};