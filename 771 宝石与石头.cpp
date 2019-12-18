#include<map>
#include<string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> jewel;
        int ret=0;
        for(int i=0;i<J.length();i++)
            jewel[J[i]]=1;
        for(int i=0;i<S.length();i++)
            ret+=jewel[S[i]];
        return ret;
    }
};