class Solution {
private:
    void trim(string& s) {
        int n = s.size();
        int i = 0, j = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') i++;

            while (i < n && s[i] != ' ') s[j++] = s[i++];

            if (s[j-1] != ' ') s[j++] = ' ';
        }

        s.resize(j-1);
    }
public:
    string reverseWords(string s) {
        trim(s);
        int l = 0, r = s.size() - 1;

        while (l <= r) swap(s[l++], s[r--]);

        for (r = 0, l = 0; r < s.size(); r++) {
            if (s[r] == ' ') {
                int idx = r - 1;
                while (l <= idx) {
                    swap(s[l++], s[idx--]);
                }

                l = r + 1;
            }  
        }

        r--;
        while (l <= r) swap(s[l++], s[r--]);
        return s;
    }
};