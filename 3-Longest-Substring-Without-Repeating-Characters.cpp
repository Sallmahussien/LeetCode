class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> my_map;
        int max_len = 0;
        int left = 0;

        for (int i = 0; i < s.size(); i++) {
            if (my_map.find(s[i]) != my_map.end() && my_map[s[i]] >= left) {
                left = my_map[s[i]] + 1;
            }
            my_map[s[i]] = i;
            if (i-left+1 > max_len) max_len = i-left+1;
        }
        return max_len;
    }
};