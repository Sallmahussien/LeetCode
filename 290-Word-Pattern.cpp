class Solution {
private:
     vector<string> split(string str) {
        vector<string> res;
        string s;
        for (char ch : str) {
            if (ch == ' ') {
                if (!s.empty()) { 
                    res.push_back(s);
                    s = \\;
                }
            } else {
                s += ch;
            }
        }
        if (!s.empty()) {
            res.push_back(s);
        }
        return res;
    }
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c_str;
        unordered_map<string, char> str_c;
        vector<string> s_arr = split(s);

        if (pattern.size() != s_arr.size()) return false;

        for (int i = 0; i < pattern.size(); i++) {
            if (!c_str.count(pattern[i])) {
                if (str_c.count(s_arr[i])) return false;

                c_str[pattern[i]] = s_arr[i];
                str_c[s_arr[i]] = pattern[i];
            } else if (c_str[pattern[i]] != s_arr[i]) {
                return false;
            }
        }

        return true;
    }
};