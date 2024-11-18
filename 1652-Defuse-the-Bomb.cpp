class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n);

        if (k == 0) return res;

        int dir = k > 0 ? 1 : -1;

        for (int i = 0; i < n; i++) {
            int sum = 0;
    
            for (int j = 1; j <= abs(k); j++) {
                int a = i + (j * dir);
                int idx = (a % n + n) % n;
                sum += code[idx];
            }

            res[i] = sum;
        }

        return res;
    }
};