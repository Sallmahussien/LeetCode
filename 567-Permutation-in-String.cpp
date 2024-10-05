class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        unordered_map<char, int> s1_map;
        for (char c : s1) {
            s1_map[c]++;
        }

        unordered_map<char, int> s2_map;

        int l = 0;

        for (int r = 0; r < s2.size(); r++) {
            s2_map[s2[r]]++;

            if (r-l+1 == s1.size()) {
                if (s1_map == s2_map) {
                    return true;
                } else {
                    s2_map[s2[l]]--;
                    if (s2_map[s2[l]] == 0) {
                        s2_map.erase(s2[l]);
                    }
                    l++;
                }
            }
        }

        return false;
    }
};