class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0); 
        int x = (n + m) * mean - sum;

        if (x < n || x > 6 * n) return {};

        vector<int> res(n, x / n);

        int remainder = x % n;
        for (int i = 0; i < remainder; i++) {
            res[i]++;
        }

        return res;
    }
};