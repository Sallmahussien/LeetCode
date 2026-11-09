class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """

        counter = {}
        for num in nums:
            counter[num] = counter.get(num, 0) + 1

        max_heap = [(-freq, num) for num, freq in counter.items()]
        heapq.heapify(max_heap)

        return [heapq.heappop(max_heap)[1] for _ in range(k)]

        