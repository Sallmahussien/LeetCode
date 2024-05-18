class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        unordered_map<char, int> jewel_int;

        for (char jewel: jewels) jewel_int[jewel]++;

        for (char stone: stones) {
            if (jewel_int.count(stone)) count++;
        }

        return count;
    }
};