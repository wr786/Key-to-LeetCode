class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        if(tomatoSlices % 2) return ans;
        if(tomatoSlices < 2*cheeseSlices || tomatoSlices > 4*cheeseSlices) return ans;
        ans.push_back(tomatoSlices/2 - cheeseSlices);
        ans.push_back(2*cheeseSlices - tomatoSlices/2);
        return ans;
    }
};