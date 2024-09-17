class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int l = 0, r = 0;
        unordered_set<char> unique_chars;

        for (; r < s.size(); r++) {
            while (unique_chars.count(s[r])) {
                unique_chars.erase(s[l++]);
            }

            unique_chars.insert(s[r]);
            len = max(len, r - l + 1);
        }

        return len;
    }
};