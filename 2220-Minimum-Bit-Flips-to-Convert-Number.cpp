class Solution {
public:
    int minBitFlips(int start, int goal) {
        int k = start^goal;
        int res = 0;

        while (k) {
            if (k % 2 == 1) res++;
            k /= 2; 
        }
        return res;
    }
};