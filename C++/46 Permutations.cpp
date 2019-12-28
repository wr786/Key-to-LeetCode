class Solution {
private:
    vector<int> a;
    int n;
    bool next_perm() {
        int changePos = -1, changePos2 = -1;
        for(int i=n-2; i>=0; i--) 
            if(a[i] < a[i+1]) {
                changePos = i;
                for(int j=n-1; j>i; j--)
                    if(a[j] > a[i]) {
                        changePos2 = j;
                        break;
                    }
                break;
            }
        if(changePos != -1) {
            swap(a[changePos], a[changePos2]);
            for(int i=changePos+1; i<=(changePos+n-1)/2; i++) // rev
                swap(a[i], a[changePos+n-i]);
            return true;
        }
        return false;
    }
public:
    // 分析：给出一个排列P，求出下一个排列P1是什么？
    // 比如 P = 1 2 3 4 5。显然P1: 1 2 3 5 4。 P2：1 2 4 3 5。
    // 规律： P->P1   :直接对 4 5 逆序。
    //        P1->P2  : 后两个元素已经是逆序了，接下来就从后往前找出第一个正序的两个元素，也就是3 5，然后把3 和 4（逆序找第一个比3大的元素）交换，再把5（包括）之后的元素逆序。就可以得到下一个排列了。.
    // 核心：逆序不可能存在下一个排列了，已经是最大了。
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end()); // 不加这个，就不一定是"全"排序
        a = nums;
        vector<vector<int>> ret;
        do{ret.push_back(a);} while(next_perm());
        return ret;
    }
};