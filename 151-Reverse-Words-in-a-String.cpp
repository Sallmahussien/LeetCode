class Solution {
private:
    void trim(string& s) {
        int n = s.size();
        int i = 0, j = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') i++;

            while (i < n && s[i] != ' ') s[j++] = s[i++];

            if (j > 0 && i < n) s[j++] = ' ';
        }

        while (j > 0 && s[j-1] == ' ') j--;

        s.resize(j);
    }

    void reverse(string& s, int start, int end) {
        while (start <= end) swap(s[start++], s[end--]);
    }

public:
    string reverseWords(string s) {
        trim(s);
        cout << s << endl;
        int n = s.size();
        reverse(s, 0, n-1);
        

        for (int r = 0, l = 0; r <= n; r++) {
            if (r == n || s[r] == ' ') {
                reverse(s, l, r-1);

                l = r + 1;
            }  
        }

        return s;
    }
};