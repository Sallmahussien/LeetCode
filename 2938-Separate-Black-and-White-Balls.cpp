class Solution {
public:
    long long minimumSteps(string s) {
        long black_count = 0;
        long long res = 0;

        for (char c : s) {
            if (c == '1') black_count++;
            else res += black_count;
        }

        return res;
    }
};