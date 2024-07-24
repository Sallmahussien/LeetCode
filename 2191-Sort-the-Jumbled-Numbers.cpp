class Solution {
private:
    static bool is_less(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if (a.first == b.first) return a.second.second < b.second.second;

        return a.first < b.first;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, pair<int, int>>> mapped_nums;

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int mapped_n = n == 0 ? mapping[0] : 0;
            int digit = 1;
            while (n) {
                int d = n % 10;
                mapped_n += digit * mapping[d];
                n /= 10;
                digit *= 10;
            }

            cout << mapped_n << endl;

            mapped_nums.push_back({mapped_n, {nums[i], i}});
        }

        sort(mapped_nums.begin(), mapped_nums.end(), is_less);

        vector<int> res;
        for (auto pair: mapped_nums) {
            res.push_back(pair.second.first);
        }

        return res;
    }
};