class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        for (int idx = 0; idx < word1.size() || idx < word2.size(); idx++) {
            if (idx < word1.size()) {
                result += word1[idx];
            }

            if (idx < word2.size()) {
                result += word2[idx];
            }
        }

        return result;
    }
};