class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> money = {
            {5, 0},
            {10, 0},
            {20, 0}
        };

        for (int bill : bills) {
            if (bill == 10) {
                if (money[5] > 0) money[5]--;
                else return false;
            } else if (bill == 20) {
                if (money[10] > 0 && money[5] > 0) {
                    money[10]--;
                    money[5]--;
                } else if (money[5] >= 3) {
                    money[5] -= 3;
                } else {
                    return false;
                }
            }

            money[bill]++;
        }
        

        return true;
    }
};