class Solution {
    public int minimumOperations(int[] nums) {
        Map<Integer, Integer> freqArr = new HashMap<>();

        for (int num : nums) {
            freqArr.put(num, freqArr.getOrDefault(num, 0) + 1);
        }

        int res = 0;
        int n = nums.length;
        int remainingSize = n;
        int idx = 0;

        while (remainingSize != freqArr.size() && idx < n) {
            for (int i = idx; i < idx + 3 && i < n; i++) {
                int currNum = nums[i];
                int currFreq = freqArr.get(currNum);

                freqArr.put(currNum, currFreq - 1);
                if (freqArr.get(currNum) == 0) {
                    freqArr.remove(currNum);
                }
            }

            idx += 3;
            remainingSize -= 3;
            res++;
        }

        return res;
    }
}