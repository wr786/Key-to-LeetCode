class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if(len < 2) return "";
        for(int i=0; i<len; i++) {
            if(palindrome[i] != 'a' && i!=len/2) {
                palindrome[i] = 'a';
                return palindrome;
            } else {
                if(i == len-1) {
                    palindrome[i] = 'b';
                    return palindrome;
                }
            }
        }
        return "";
    }
};