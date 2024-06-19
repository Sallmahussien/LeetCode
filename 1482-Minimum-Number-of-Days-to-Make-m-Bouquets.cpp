class Solution {
private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int days) {
        int flowers = 0, bouquets = 0;
        for (int bloom : bloomDay) {
            if (days >= bloom) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    if (bouquets == m) return true;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m*k > bloomDay.size()) return -1;

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while (left < right) {
            int mid = left + ((right-left)/2);
            if (canMakeBouquets(bloomDay, m, k, mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};