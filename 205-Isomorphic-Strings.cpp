class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s_t;
        map<char, char> t_s;

        string str1 = \\;
        string str2 = \\;

        for (int i = 0; i < s.size(); i++) {
            if (s_t.find(s[i]) == s_t.end()) s_t[s[i]] = t[i];
            if (t_s.find(t[i]) == t_s.end()) t_s[t[i]] = s[i];

            str1 += s_t[s[i]];
            str2 += t_s[t[i]];
        }

        return str1 == t && str2 == s;
    }
};