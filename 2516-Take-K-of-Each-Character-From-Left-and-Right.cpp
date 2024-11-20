class Solution {
private:
    int get_min(vector<int>& arr) {
        int min_num = INT_MAX;

        for (int n : arr) {
            min_num = min(min_num, n);
        }

        return min_num;
    }
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3);

        for (char c : s) {
            count[c-'a']++;
        }

        if (count[0] < k || count[1] < k || count[2] < k) {
            return -1;
        }

        int n = s.size();
        int l = 0;
        int res = INT_MAX;

        for (int r = 0; r < n; r++) {
            count[s[r]-'a']--;

            while (l <= r && get_min(count) < k) {
                count[s[l]-'a']++;
                l++;
            }

            res = min(res, n-(r-l+1));
        }
        return res;
    }
};