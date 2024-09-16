class Solution {
private:
    int toMinutes(string time) {
        int h = (time[0] - 48) * 10 + (time[1] - 48);
        int m = (time[3] - 48) * 10 + (time[4] - 48);

        int t = h * 60 + m;

        return t;
    }

public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for (string timePoint : timePoints) {
            minutes.push_back(toMinutes(timePoint));
        }

        sort(minutes.begin(), minutes.end());
        int res = INT_MAX;
        for (int i = 0; i < minutes.size()-1; i++) {
            res = min(res, abs(minutes[i] - minutes[i+1]));
        }

        res = min(res, 1440 - minutes.back() + minutes.front());

        return res;
    }
};