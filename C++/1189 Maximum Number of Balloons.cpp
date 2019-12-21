#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int len=text.length();
        int b=0,a=0,l=0,o=0,n=0;
        for(int i=0;i<len;i++)
        {
            if(text[i]=='b') b++;
            if(text[i]=='a') a++;
            if(text[i]=='l') l++;
            if(text[i]=='o') o++;
            if(text[i]=='n') n++;
        }
        int balloons=min(b,a);
        balloons=min(balloons,o/2);
        balloons=min(balloons,l/2);
        balloons=min(balloons,n);
        return balloons;
    }
};