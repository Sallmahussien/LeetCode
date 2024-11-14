class Solution {
private:
    bool can_distribute(int n, vector<int>& quantities, int x) {
        int idx = 0, m = quantities.size();
        int remaining = quantities[idx];

        for (int i = 0; i < n; i++) {
            // iterate through each store
            if (remaining <= x) {
                idx++;
                if (idx == m) return true;

                remaining = quantities[idx];
            } else {
                remaining -= x;
            }
        }

        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1;
        int h = *std::max_element(quantities.begin(), quantities.end());

        while (l < h) {
            int mid = l + ((h-l)/2); 
            bool can_dist = can_distribute(n, quantities, mid);

            if (can_dist) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};