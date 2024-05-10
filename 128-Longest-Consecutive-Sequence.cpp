class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // answer one with o(nlogn)
        // if (nums.size() == 0) return 0;
        
        // sort(nums.begin(), nums.end());
        
        // int length = 1;
        // int max_length = 1;
        
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] == nums[i-1]) continue;
        //     if (nums[i] == nums[i-1] + 1) length++;
        //     else {
        //         if (length > max_length) max_length = length;
        //         length = 1;
        //     }
        // }

        // if (length > max_length) max_length = length;

        // return max_length;

        // second solution
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        int maxLength = 0;
        
        for (int num : nums) {
            // If the current number is the start of a sequence
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentLength = 0;
                
                while (numSet.count(currentNum)) {
                    currentNum++;
                    currentLength++;
                }
                
                maxLength = std::max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};