class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copyed = arr;
        sort(copyed.begin(), copyed.end());
        int n = arr.size(), idx=0;
        map<int, int> index;
        for(int i=0; i<n; i++) {
            if(!index[copyed[i]])
                index[copyed[i]] = ++idx;
        }
        for(int i=0; i<n; i++) 
            copyed[i] = index[arr[i]];
        return copyed;
    }
};