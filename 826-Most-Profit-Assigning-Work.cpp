class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {difficulty[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0, totalProfit = 0, idx = 0;
        for (int w : worker) {
            while (idx < n && w >= jobs[idx].first) {
                maxProfit = max(maxProfit, jobs[idx].second);
                idx++;
            }

            totalProfit += maxProfit;
        }

        return totalProfit;
    }
};