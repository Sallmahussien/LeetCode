class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;

        for (string detail : details) {
            int age = (detail[11] - 48) * 10 + (detail[12] - 48);
            if (age > 60) res ++;
        }

        return res;
    }
};