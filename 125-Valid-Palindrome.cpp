class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i <= j) {
            while(i < j && !_isalnum(s[i])) i++;
            while(i < j && !_isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }

        return true;
        
    }

    bool _isalnum(char c) {
        if ((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            return true;
        }

        return false;
    }
};