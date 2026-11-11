class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        max_sum, summ = None, 0

        for i in range(len(nums)):
            summ += nums[i]

            if i >= k - 1:
                max_sum = summ if max_sum is None else max(max_sum, summ)
                summ -= nums[i - k + 1]

        return max_sum / k
        