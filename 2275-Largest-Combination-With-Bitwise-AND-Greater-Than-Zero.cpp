class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bit_counts[32] = {0};

        for (int num : candidates) {
            // For each bit position from 0 to 31
            for (int i = 0; i < 32; ++i) {
                // Check if the i-th bit is set in num
                if (num & (1 << i)) {
                    // Increment the count for that bit position
                    bit_counts[i]++;
                }
            }
        }

        return *max_element(bit_counts, bit_counts + 32);
        
    }
};