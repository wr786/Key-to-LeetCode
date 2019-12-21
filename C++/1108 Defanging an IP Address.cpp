#include<string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        int len=address.length();
        string ret="";
        for(int i=0;i<len;i++)
        {
            if(address[i]!='.')
                ret+=address[i];
            else
                ret+="[.]";
                //ret+='['+address[i]+']';
        }
        return ret;
    }
};