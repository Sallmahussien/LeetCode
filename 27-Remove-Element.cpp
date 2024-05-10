class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, j = nums.size() - 1;
        int k = 0;

        if (j == 0 && nums[0] == val) return 0;

        for (i = 0; i < nums.size()  && i < j; i++) {
            if (nums[i] == val) {
                while (j > i && nums[j] == val) j--;
                if (j == i && nums[j] == val) break;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
            }
            k++;
        }
        if (i == j && nums[j] != val) k++;

        return k;
        
    }
};