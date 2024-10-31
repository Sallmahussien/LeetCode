class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size(), m = factory.size();
        
        // Sort robots and factories by position
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // dp array to store the minimum distances, initialized with large values
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        dp[0][0] = 0; // No robots assigned means zero distance
        
        // DP to compute the minimum distance
        for (int j = 1; j <= m; ++j) {  // For each factory
            dp[0][j] = 0;  // 0 robots can always be assigned with 0 distance

            for (int i = 1; i <= n; ++i) {  // For each robot
                long long cost = 0;
                dp[i][j] = dp[i][j - 1];  // Option to not use this factory

                for (int k = 1; k <= factory[j - 1][1] && k <= i; ++k) {  // Assign k robots
                    cost += abs(robot[i - k] - factory[j - 1][0]);
                    
                    // Only update if dp[i - k][j - 1] is not LLONG_MAX
                    if (dp[i - k][j - 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                    }
                }
            }
        }

        // The result is the minimum distance to repair all robots using all factories
        return dp[n][m];
    }
};

