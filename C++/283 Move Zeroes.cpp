class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]) {
                nums[left] = nums[i];
                if(left != i) nums[i] = 0;
                left++;
            }
        }
        return;
    }
};