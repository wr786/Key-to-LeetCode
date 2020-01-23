class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), left = 0; // 双指针法
        if(n == 0) return 0;
        for(int i=1; i<n; i++)
           if(nums[i] != nums[left])
               nums[++left] = nums[i];
        return left+1;
    }
};