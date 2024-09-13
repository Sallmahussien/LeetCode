class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        vector<int> prefix_xor;
        int prefix = 0;
        for (int n : arr) {
            prefix ^= n;
            prefix_xor.push_back(prefix);
        }

        for (vector<int> query: queries) {
            int x = prefix_xor[query[1]];
            if (query[0] > 0) x ^= prefix_xor[query[0]-1];

            res.push_back(x);
        }

        // for (vector<int> query : queries) {
        //     int x = 0;
        //     for (int i = query[0]; i <= query[1]; i++) {
        //         x ^= arr[i];
        //     }

        //     res.push_back(x);
        // }

        return res;
    }
};