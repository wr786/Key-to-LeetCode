class Solution {
public:
    vector<vector<int>> 
    generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows == 0) {return ret;}
        vector<int> firstRow; firstRow.push_back(1); ret.push_back(firstRow);
        for(int i=1; i<numRows; i++) {
            vector<int> curRow;
            curRow.push_back(1);
            for(int j=1; j<i; j++) 
                {curRow.push_back(ret[i-1][j-1] + ret[i-1][j]);}
            curRow.push_back(1);
            ret.push_back(curRow);
        } 
        return ret;
    }
};