class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;

        for (auto interval : intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int j = 0;
        int res = 0;

        for (int i = 0; i < start.size(); i++) {
            while (start[i] > end[j]) {
                j++;
            }

            res = max(res, i-j+1);
        }

        return res;
        
    }
};