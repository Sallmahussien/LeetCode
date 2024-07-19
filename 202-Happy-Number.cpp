class Solution {
public:
    bool isHappy(int n) {
        // 2 => 2^2 => 4
        // 4 => 4^2 => 16
        // 16 => 1^2 + 6^2 = 37
        // 37 => 3^2 + 7^2 = 58
        // 58 => 6^2 + 8^2 => 89
        // 89 => 8^2 + 9^2 = 145
        // 145 => 1 + 16 + 25 = 42 => smaller than the previous iteration so return false
        // 42 => 16 + 4 => 20
        // 20 => 2 + 0 => 4

        unordered_set<int> unique_nums;
        int num = n;

        while (!unique_nums.count(num)) {
            unique_nums.insert(num);
            int new_num = 0;
            while (num) {
                int digit = num % 10;
                new_num += pow(digit, 2);
                num /= 10;
            }

            if (new_num == 1) return true;

            num = new_num;
        }

        return false;
    }
};