class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglies(n);
        uglies[0] = 1;

        int i = 0, j = 0, k = 0;

        for (int idx = 1; idx < n; idx++) {
            int two_factor = uglies[i] * 2;
            int three_factor = uglies[j] * 3;
            int five_factor = uglies[k] * 5;

            int next_ugly = min(two_factor, min(three_factor, five_factor));
            uglies[idx] = next_ugly;

            if (next_ugly == two_factor) i++;
            if (next_ugly == three_factor) j++;
            if (next_ugly == five_factor) k++;
        }

        for (int ugly : uglies) {
            cout << ugly << endl;
        }

        return uglies.back();
    }
};