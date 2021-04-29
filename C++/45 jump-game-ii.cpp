class Solution {
public:
    int ans = INT_MAX;
    void search(vector<int>& nums, int curpos, int jumps) {
        if(curpos == nums.size() - 1) {
            ans = min(ans, jumps);
            return;
        }
        if(curpos + nums[curpos] >= nums.size() - 1) {
            ans = min(ans, jumps + 1);
            return;
        }
        if(nums[curpos] < 1) return;
        int bestjumppos = curpos+1;
        int tmp = nums.size()-curpos-1;
        for(int i=2; i<=min(nums[curpos], tmp); i++) {
            // 贪心，选择能到达的地方最远的地方跳
            if(nums[curpos+i] + curpos+i > nums[bestjumppos] + bestjumppos) {
                bestjumppos = curpos + i;
            }
        }
        search(nums, bestjumppos, jumps+1);
    }
    int jump(vector<int>& nums) {
        search(nums, 0, 0);
        return ans;
    }
};