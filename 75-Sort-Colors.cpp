class Solution {
public:
    void sortColors(vector<int>& nums) {

        // insertion sort o(n^2)
        // for (int i = 1; i < nums.size(); i++) {
        //     for (int j = i-1; j >= 0 && nums[j+1] < nums[j]; j--) {
        //         swap(nums[j+1], nums[j]);
        //     }
        // }

        // bucket sort, o(n) time and o(1) memory
        vector<int> count(3);
        for (int num : nums) {
            count[num]++;
        }

        int idx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < count[i]; j++) {
                nums[idx++] = i;
            }
        }

        // int low = 0, mid = 0, high = nums.size() - 1;

        // while(mid <= high) {
        //     if (nums[mid] == 0) {
        //         swap(nums[mid], nums[low]);
        //         mid++, low++;
        //     } else if (nums[mid] == 2) {
        //         swap(nums[mid], nums[high]);
        //         high--;
        //     } else if (nums[mid] == 1) mid++;
        // }

        
        
    }

    void print_arr(vector<int>& nums) {
        for (auto num: nums) cout << num << \ \;
        cout << endl;
    }
};