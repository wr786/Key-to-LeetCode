class Solution {
private:
    map<char, string> dict;
    map<string, char> anti_dict;
public:
    bool wordPattern(string pattern, string str) {
        int m = pattern.length(), n = str.length();
        // 分词
        vector<string> words;
        while(n) {
            int posSpace = str.find(" ");
            if(posSpace < 0 || posSpace >= n) break;
            words.push_back(str.substr(0, posSpace));
            str = str.substr(posSpace+1, n);
            n = str.length();
        }
        if(n) words.push_back(str);
        n = words.size();
        if(m != n) return false; // bug-free
        for(int i=0; i<m; i++) {
            if(dict[pattern[i]] == "" && !anti_dict[words[i]]) {
                dict[pattern[i]] = words[i];
                anti_dict[words[i]] = pattern[i];
            } else if(dict[pattern[i]] != words[i] || anti_dict[words[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};