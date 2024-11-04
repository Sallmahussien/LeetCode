class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int idx = 0;

        while (idx < word.size()) {
            int count = 0;
            char c = word[idx];

            while (idx < word.size() && word[idx] == c && count < 9) {
                idx++;
                count++;
            }

            comp += to_string(count) + c;
        }

        return comp;
    }
};