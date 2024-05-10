class Solution {
public:
    void sortColors(vector<int>& nums) {

        // for (int i = 1; i < nums.size(); i++) {
        //     for (int j = i; j > 0; j--) {
        //         if (nums[j - 1] < nums[j]) break;

        //         int temp = nums[j];
        //         nums[j] = nums[j - 1];
        //         nums[j - 1] = temp;
        //     }
        // }

        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++, low++;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else if (nums[mid] == 1) mid++;
        }
        
    }

    void print_arr(vector<int>& nums) {
        for (auto num: nums) cout << num << \ \;
        cout << endl;
    }
};