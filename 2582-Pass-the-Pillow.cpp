class Solution {
public:
    int passThePillow(int n, int time) {
        int cycles = time / (n - 1); 
        int remainder = time % (n - 1);

        return cycles % 2 == 0 ? remainder + 1 : n - remainder;
        
    }
};