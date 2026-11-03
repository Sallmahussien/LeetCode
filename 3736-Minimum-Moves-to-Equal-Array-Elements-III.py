class Solution:
    def minMoves(self, nums: List[int]) -> int:
        max_v = max(nums)
        result = 0

        for num in nums:
            result += (max_v - num)

        return result
        