class Solution {
private:
    int numLength(int num) {
        int res = 0;

        while (num) {
            res += 1;
            num /= 10;
        }

        return res;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        int res = 0;

        for (int n : arr1) {
            int num = n;

            while (num) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        for (int n : arr2) {
            int num = n;

            while (num) {
                if (prefixes.count(num)) {
                    res = max(res, num);
                    break;
                }

                num /= 10;
            }
        }

        return res == 0 ? res : numLength(res);
    }
};