class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        unordered_map<char, int> freq_arr;
        int odd_flag = false;

        for(char c: s) {
            freq_arr[c]++;
        }
        
        for (auto pair: freq_arr) {
            if (pair.second % 2 == 0) res += pair.second;
            else {
                res += pair.second - 1;
                odd_flag = true;
            };
        }

        return odd_flag ? res + 1 : res;
    }
};