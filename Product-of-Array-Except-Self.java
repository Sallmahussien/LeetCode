class Solution {
    public int[] productExceptSelf(int[] nums) {
        int totalProduct = 1;
        boolean haveZero = false;

        for (int num : nums) {
            if (num == 0 && !haveZero) {
                haveZero = true;
            } else {
                totalProduct *= num;
            }
        }

        for (int i = 0; i < nums.length; i++) {
            if (haveZero){
                if (nums[i] == 0) nums[i] = totalProduct;
                else nums[i] = 0;
            } else {
                nums[i] = totalProduct / nums[i];
            }
        }

        return nums;
    }
}