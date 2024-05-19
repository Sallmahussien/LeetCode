class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
    
        unordered_map<char, int> freq_s1;

        for (char s: s1) {
            freq_s1[s]++;
        }

        int window_size = s1.size();

        for (int i = 0; i < s2.size()-window_size+1; i++) {
            unordered_map<char, int> freq_window;
            for (int j = 0; j < window_size; j++) {
                freq_window[s2[i+j]]++;
            }

            if (freq_s1 == freq_window) return true;
        }

        return false;   
    }
};