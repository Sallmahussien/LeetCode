class Solution {
private:
    bool static compare(const vector<int>& v1, const vector<int>& v2) {
        return (double)v1[0] / v1[1] < (double)v2[0] / v2[1];
    }

public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<int>> fractions;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i+1; j < arr.size(); j++) {
                fractions.push_back({arr[i], arr[j]});
            }
        }

        sort(fractions.begin(), fractions.end(), compare);

        return fractions[k-1];
    }
};