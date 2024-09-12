class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        unordered_set<char> allowed_char(allowed.begin(), allowed.end());
        
        for (string word : words) {
            bool is_allowed = true;

            for (char c : word) {
                if (!allowed_char.count(c)) {
                    is_allowed = false;
                    break;
                }
            }

            res += is_allowed;
        }

        return res;
    }
};