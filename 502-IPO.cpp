class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int totalCapital = w;
        int idx = 0;

        for (int i = 0; i < k; ++i) {
            while (idx < profits.size() && totalCapital >= projects[idx].first) {
                maxHeap.push(projects[idx].second);
                idx++;
            }

            if (maxHeap.empty()) break;

            totalCapital += maxHeap.top();
            maxHeap.pop();
        }

        return totalCapital;
    }
};