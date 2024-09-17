class Solution {
private:
    unordered_map<string, int> splitSentence(string s) {
        unordered_map<string, int> res;
        string str = "";

        for (char c : s) {
            if (c == ' ') {
                res[str] += 1;
                str = "";
            } else {
                str += c;
            }
        }

        res[str] += 1;

        return res;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq_arr1 = splitSentence(s1);
        unordered_map<string, int> freq_arr2 = splitSentence(s2);
        vector<string> res;

        for (auto pair : freq_arr1) {
            if (pair.second == 1 && !freq_arr2.count(pair.first)) {
                res.push_back(pair.first);
            }
        }

        for (auto pair : freq_arr2) {
            if (pair.second == 1 && !freq_arr1.count(pair.first)) {
                res.push_back(pair.first);
            }
        }

        return res;
    }
};