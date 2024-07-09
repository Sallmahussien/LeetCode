class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long start_time = 0, sum = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (start_time < customers[i][0]) start_time = customers[i][0];

            sum += start_time + customers[i][1] - customers[i][0];

            start_time = start_time + customers[i][1];
        }

        return (double)sum / customers.size();
        
    }
};