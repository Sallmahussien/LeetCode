class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = s.size() - 1;
        int length = 0;

        while(s[idx] == ' ') idx--;

        while(idx >= 0 && s[idx] != ' ') {
            length++;
            idx--;
        }

        return length;
    }
};