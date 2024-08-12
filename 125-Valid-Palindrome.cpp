class Solution {
private:
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            while (l < s.size() && !isAlphanumeric(s[l])) l++;
            while (r >= 0 && !isAlphanumeric(s[r])) r--;

            if (l >= r) break;

            if (tolower(s[l]) != tolower(s[r])) return false;

            l++, r--;
        }

        return true;
    }
       
};