class Solution {
private:
    int n;
    struct Interval {
        int left;
        int right;
        int idx;
    };
    vector<Interval> sortedIntervals;
    static bool cmp(Interval A, Interval B) {return A.left < B.left;}
    int findRightItv(int curRightPos) {
        int l = 0, r = n-1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(sortedIntervals[mid].left < curRightPos) l = mid + 1;
            else r = mid;
        }
        return sortedIntervals[l].left >= curRightPos ? sortedIntervals[l].idx : -1;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        n = intervals.size();
        for(int i=0; i<n; i++) {
            Interval *cur = new Interval;
            cur->left = intervals[i][0];
            cur->right = intervals[i][1];
            cur->idx = i;
            sortedIntervals.push_back(*cur);
        }
        sort(sortedIntervals.begin(), sortedIntervals.end(), cmp);
        for(int i=0; i<n; i++) ans.push_back(findRightItv(intervals[i][1]));
        return ans;
    }
};