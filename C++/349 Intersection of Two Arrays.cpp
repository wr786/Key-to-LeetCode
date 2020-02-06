class Solution {
private:
    unordered_set<int> inNums1;
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int n = nums1.size();
        for(int i=0; i<n; i++)
            inNums1.insert(nums1[i]);
        n = nums2.size();
        for(int i=0; i<n; i++) {
            if(inNums1.count(nums2[i])) {
                ret.push_back(nums2[i]);
                inNums1.erase(nums2[i]);
            }
        }
        return ret;
    }
};