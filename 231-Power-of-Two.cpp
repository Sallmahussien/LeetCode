class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if (n <= 0) return false;

        // double num = log2(n);
        // return floor(num) == num;

        return (n > 0) && !(n & (n - 1));
    }
};