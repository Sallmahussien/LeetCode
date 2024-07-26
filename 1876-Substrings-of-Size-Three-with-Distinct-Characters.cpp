class Solution {
public:
    int countGoodSubstrings(string s) {
        int start = 0, res = 0;
        unordered_set<char> unique_chars;

        for (int end = 0; end < s.size(); end++) {
            while (unique_chars.count(s[end])) {
                unique_chars.erase(s[start++]);
            }

            unique_chars.insert(s[end]);

            if (end - start + 1 == 3) {
                res += 1;
                unique_chars.erase(s[start++]);
            }
        }

        return res;
    }
};