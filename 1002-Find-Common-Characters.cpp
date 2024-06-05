class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq_arr(26);
        vector<string> res;

        for (char c : words[0]) {
            freq_arr[c - 'a']++;
        }

        for (int i = 1; i < words.size(); i++) {
            vector<int> curr_freq(26);

            for (char c : words[i]) {
                curr_freq[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                freq_arr[i] = min(freq_arr[i], curr_freq[i]);
            }
        }

        for (int i = 0; i < 26; i++) {
            while (freq_arr[i] > 0) {
                res.push_back(string(1, 'a' + i)); 
                freq_arr[i]--;
            }
        }

        return res;   
    }
};