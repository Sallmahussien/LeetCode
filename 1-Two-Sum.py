class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        counter = {}
        for i, num in enumerate(nums):
            diff = target - num
            if diff in counter and i != counter[diff]:
                return [i, counter[diff]]
            counter[num] = i

        return []
