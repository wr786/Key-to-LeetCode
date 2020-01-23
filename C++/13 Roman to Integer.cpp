class Solution {
public:
    int romanToInt(string s) {
        int l = s.length();
        if(l == 0) return 0;
        switch(s[0]) {
            case 'M': return 1000 + romanToInt(s.substr(1));
            case 'D': return 500 + romanToInt(s.substr(1));
            case 'C':
                if(l > 1) {
                    switch(s[1]) {
                        case 'M': return 900 + romanToInt(s.substr(2));
                        case 'D': return 400 + romanToInt(s.substr(2));
                        default: return 100 + romanToInt(s.substr(1));
                    }
                }
                return 100 + romanToInt(s.substr(1));
            case 'L': return 50 + romanToInt(s.substr(1));
            case 'X':
                if(l > 1) {
                    switch(s[1]) {
                        case 'L': return 40 + romanToInt(s.substr(2));
                        case 'C': return 90 + romanToInt(s.substr(2));
                        default: return 10 + romanToInt(s.substr(1));
                    }
                }
                return 10 + romanToInt(s.substr(1));
            case 'V': return 5 + romanToInt(s.substr(1));
            case 'I':
                if(l > 1) {
                    switch(s[1]) {
                        case 'V': return 4 + romanToInt(s.substr(2));
                        case 'X': return 9 + romanToInt(s.substr(2));
                        default: return 1 + romanToInt(s.substr(1));
                    }
                }
                return 1 + romanToInt(s.substr(1));
            default: return 0;
        }
    }
};