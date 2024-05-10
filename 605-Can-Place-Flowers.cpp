class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;

        int planted_num = 0;
        int size = flowerbed.size();

        for(int i = 0; i < size; i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == size-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                planted_num++;

                if (planted_num == n) return true;
            }
        }

        return false;
        
    }
};