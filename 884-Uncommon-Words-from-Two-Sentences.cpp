class Solution {
private:
    void splitSentence(unordered_map<string, int>& freq_arr, string s) {
        string str = "";

        for (char c : s) {
            if (c == ' ') {
                freq_arr[str] += 1;
                str = "";
            } else {
                str += c;
            }
        }

        freq_arr[str] += 1;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq_arr;
        splitSentence(freq_arr, s1);
        splitSentence(freq_arr, s2);
        vector<string> res;

        for (auto pair : freq_arr) {
            if (pair.second == 1) {
                res.push_back(pair.first);
            }
        }

        return res;
    }
};