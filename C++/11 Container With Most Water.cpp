class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int leftPtr = 0, rightPtr = n-1; // 双指针法
        int ret = 0;
        while(leftPtr < rightPtr) {
            ret = max(ret, min(height[leftPtr], height[rightPtr]) * (rightPtr - leftPtr));
            height[leftPtr] <= height[rightPtr]? leftPtr++ : rightPtr--;
        }
        return ret;
    }
};