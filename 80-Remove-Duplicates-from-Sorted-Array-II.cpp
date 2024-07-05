class Solution {
private:
    int _min(int num1, int num2) {
        if (num1 < num2) return num1;
        return num2;
    }

public:
    int removeDuplicates(vector<int>& nums) {
        // int l = 0, r = 0;

        // while(r < nums.size()) {
        //     int count = 1;

        //     while (r + 1 < nums.size() && nums[r] == nums[r+1]) count++, r++;

        //     for (int i = 0; i < min(2, count); i++) {
        //         nums[l] = nums[r];
        //         l++;
        //     }

        //     r++;
        // }

        // return l;


        if (nums.size() < 3) return nums.size(); 
        int l = 1;
        for (int r = 2; r < nums.size(); r++) {
            if ((nums[l] == nums[l-1] && nums[l] != nums[r]) || (nums[l-1] != nums[r])) {
                nums[++l] = nums[r];
            }
        }

        return l+1;


















    }
};