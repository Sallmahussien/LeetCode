class Solution {
public:
    bool isSubsequence(string s, string t) {
        char *ptr_s = s.data();
        char *ptr_t = t.data();

        while(*ptr_s != '\\0' && *ptr_t != '\\0') {
            if (*ptr_s == *ptr_t) {
                ptr_s++;  
            }
            ptr_t++;
        }

        return *ptr_s == '\\0';
    }
};