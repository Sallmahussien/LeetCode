class Solution {
public:
    int minSwaps(string s) {
        int close = 0, max_close = 0;

        for (char c : s) {
            if (c == ']') close++;
            else close--;

            max_close = max(max_close, close);
        }

        return (max_close + 1) / 2;
    }
};