class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return true;
        int end = len-1;
        for(int i=len-2; i>=0; i--)
            if(i + nums[i] >= end) 
                end = i;
        return end == 0;
    }
};