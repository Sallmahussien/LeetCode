class Solution {
private: 
    bool is_vowel(char c) {
        unordered_set vowels = {'a', 'e', 'i', 'o', 'u'};

        return vowels.count(c);
    }

public:
    int maxVowels(string s, int k) {
        int res = 0;
        int vowels_num = 0;

        for (int end = 0, start = 0; end < s.size(); end++) {
            if (is_vowel(s[end])) vowels_num++;

            if (end+1 >= k) {
                res = max(res, vowels_num);
                if (is_vowel(s[start++])) vowels_num--;
            }

        }

        return res;
    }
};