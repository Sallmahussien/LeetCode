class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() < 3) return false;

        for (int i = 0; i < arr.size()-2; i++) {
            int num = 1;
            for (int j = 0; j < 3; j++) {
                num &= arr[i+j];
            }

            if (num == 1) return true;
        }

        return false;
    }
};