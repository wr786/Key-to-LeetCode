class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            vector<int> ret;
            ret.push_back(-1); ret.push_back(-1);
            return ret;
        } // bug-free
        int l = 0, r = nums.size();
        int lowerbound = -1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) {
                r = mid;
                if(lowerbound == -1) lowerbound = mid;
                else lowerbound = min(lowerbound, mid);
            }
            else if(nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        l = max(0, lowerbound); r = nums.size();
        int upperbound = -1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) {
                l = mid + 1;
                upperbound = max(upperbound, mid);
            }
            else if(nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        vector<int> ret;
        ret.push_back(lowerbound); ret.push_back(upperbound);
        return ret;
    }
};