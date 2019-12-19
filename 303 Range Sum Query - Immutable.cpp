class NumArray {
private:
    vector<int> presum; // prefixSum
public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        if(len > 0) {
            presum.push_back(nums[0]);
            for(int i=1; i<len; i++) {
                presum.push_back(presum[i-1] + nums[i]);
            }
        } 
    }
    
    int sumRange(int i, int j) {
        int first = 0;
        if(i != 0) first = presum[i-1];
        return presum[j] - first;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */