class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long res = 0;

        for (int i = 0; i < k; i++) {
            if (happiness[i] > 0) res += happiness[i];
            if (i+1 < happiness.size()) happiness[i+1] -= (i + 1);
        }

        return res;
    }
};