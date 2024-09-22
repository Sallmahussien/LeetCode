class Solution {
private:
    int countNodesInRange(long long current, long long n) {
        long long next = current + 1;
        long long count = 0;

        while (current <= n) {
            count += min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return count;
    }

public:
    int findKthNumber(int n, int k) {
        int current = 1;
        k--;

        while (k > 0) {
            int count = countNodesInRange(current, n);
            if (count <= k) {
                current++;
                k -= count;
            } else {
                current *= 10;
                k--;
            }
        }
        
        return current;
    }
};
