class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> sufMax = arr;
        int n = arr.size();
        if(n <= 0) return arr; // bug-free
        sufMax[n-1] = -1;
        for(int i=n-2; i>=0; i--)
            sufMax[i] = max(sufMax[i+1], arr[i+1]);
        return sufMax;
    }
};