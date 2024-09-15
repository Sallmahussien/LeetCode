class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowels_bitmask = {
            {'a', 1},
            {'e', 2},
            {'i', 4},
            {'o', 8},
            {'u', 16}
        };
        unordered_map<int, int> bitmask_pos = {
           {0, -1}
        };
        int bitmask = 0;
        int len = 0;

        for (int i = 0; i < s.size(); i++) {
            if (vowels_bitmask.count(s[i])) {
                bitmask ^= vowels_bitmask[s[i]];
                if (!bitmask_pos.count(bitmask)) {
                    bitmask_pos[bitmask] = i;
                }
            }

            if (bitmask_pos.count(bitmask)) {
                len = max(len, i - bitmask_pos[bitmask]);
            }
        }

        return len;
    }
};