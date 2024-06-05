class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> freq_arr;
        vector<string> res;

        for (char c : words[0]) {
            freq_arr[c]++;
        }

        for (int i = 1; i < words.size(); i++) {
            unordered_map<char, int> curr_freq;

            for (char c : words[i]) {
                curr_freq[c]++;
            }

            for (auto &pair : freq_arr) {
                pair.second = min(pair.second, curr_freq[pair.first]);
            }
        }

        for (auto pair : freq_arr) {
            while (pair.second > 0) {
                res.push_back(string(1, pair.first));
                pair.second--;
            }
        }

        return res;   
    }
};