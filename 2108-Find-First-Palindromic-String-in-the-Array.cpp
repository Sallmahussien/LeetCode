class Solution {
private:
    bool isPalin(string& word) {
        int l= 0, r = word.size()-1;
        while (l <= r) {
            if (word[l] != word[r]) return false;

            l++;
            r--;
        }

        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        for (string word : words) {
            if (isPalin(word)) return word;
        }

        return "";
    }
};