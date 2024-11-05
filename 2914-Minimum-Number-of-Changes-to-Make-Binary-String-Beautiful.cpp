class Solution {
public:
    int minChanges(string s) {
        int changes_num = 0;

        for (int i = 0; i < s.size(); i+=2) {
            if (s[i] != s[i+1]) changes_num++;
        }

        return changes_num;
    }
};