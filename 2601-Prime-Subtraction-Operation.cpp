class Solution {
private:
    vector<bool> get_primes() {
        vector<bool> is_prime(1000, true);
        is_prime[0] = false, is_prime[1] = false;
        for (int i = 2; i < 1000; i++) {
            if (is_prime[i]) {

                for (int j = i * i; j < 1000; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        return is_prime;
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> is_prime = get_primes();

        int prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            int upper_bound = nums[i] - prev;

            int p = 0;
            for (int i = upper_bound-1; i >= 2; i--) {
                if (is_prime[i]) {
                    p = i;
                    break;
                }
            }

            if (nums[i] - p <= prev) return false;

            prev = nums[i] - p;
        }

        return true;
    }
};