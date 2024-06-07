class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict_set(dictionary.begin(), dictionary.end());
        int idx = 0;
        string res = \\;
        int n = sentence.size();

        while (idx < n) {
            string curr_word = \\;
            bool isFound = false;

            while (idx < n && sentence[idx] != ' ') {
                if (!isFound) curr_word += sentence[idx];

                if (dict_set.count(curr_word)) {
                    isFound = true;
                }
                idx++;
            }

            res += curr_word;
            if (idx < n) res += sentence[idx];
            idx++;
        }

        return res;
    }
};