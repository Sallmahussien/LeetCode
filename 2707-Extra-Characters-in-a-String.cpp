class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n+1);

        for (int i = n-1; i >= 0; i--) {
            dp[i] = 1 + dp[i+1];

            for (int j = 1; j + i <= s.size(); j++) {
                string str = s.substr(i, j);
                if (dict.count(str)) {
                    dp[i] = min(dp[i], dp[i + j]);
                }
            }
        }

        return dp[0];
    }
};