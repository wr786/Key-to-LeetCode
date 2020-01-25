class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        int n = s.length();
        for(int i=0; i<n; i++) {
            if(isalpha(s[i])) str += tolower(s[i]);
            else if(isdigit(s[i])) str += s[i];
        }
        n = str.length();
        for(int i=0; i<n/2; i++) 
            if(str[i] != str[n-1-i])
                return false;
        return true;
    }
};