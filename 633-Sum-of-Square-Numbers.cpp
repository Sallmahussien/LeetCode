class Solution {
public:
    bool judgeSquareSum(int c) {
        // long long a = 0;

        // while (a * a <= c) {
        //     double b = sqrt(c - (a * a));
        //     if (b == (int)b) return true;

        //     a += 1;
        // }

        // return false;


        int l = 0, r = sqrt(c);
        while(l <= r) {
            long long result = pow(l, 2) + pow(r, 2);
            if (result == c) return true;

            if (result > c) r--;
            else l++;
        }

        return false;
    }
};