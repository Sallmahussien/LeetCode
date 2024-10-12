class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return \\;

        unordered_map<char, int> freq_arr_t;
        unordered_map<char, int> freq_arr_s;

        for (char c : t) {
            freq_arr_t[c]++;
        }

        int l = 0, have = 0, need = freq_arr_t.size();
        int min_len = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            if (freq_arr_t.count(c)) {
                freq_arr_s[c]++;

                if (freq_arr_s[c] == freq_arr_t[c]) have++;

                while (have == need) {
                    if (r-l+1 < min_len) {
                        min_len = r-l+1;
                        start = l;
                    }

                    char l_c = s[l];
                    if (freq_arr_s.count(l_c)) {
                        freq_arr_s[l_c]--;

                        if (freq_arr_s[l_c] < freq_arr_t[l_c]) have--;
                    }
                    l++;
                }
            }
        }

        return min_len == INT_MAX ? \\ : s.substr(start, min_len);
    }
};