class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end());
        int idx = 0;

        string res = \\;

        while (idx < sentence.size()) {
            string curr_word = \\;
            while (idx < sentence.size() && sentence[idx] != ' ') {
                curr_word += sentence[idx];
                idx++;
            }

            for (string word : dictionary) {
                if (curr_word.size() >= word.size() && curr_word.substr(0, word.size()) == word) {
                    curr_word = word;
                    break;
                }
            }

            res += curr_word;
            if (idx < sentence.size()) res += sentence[idx];
            idx++;
        }

        return res;
    }
};