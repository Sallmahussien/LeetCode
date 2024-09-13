class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;

        for (vector<int> query : queries) {
            int x = 0;
            for (int i = query[0]; i <= query[1]; i++) {
                x ^= arr[i];
            }

            res.push_back(x);
        }

        return res;
    }
};