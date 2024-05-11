class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        res = float("inf")
        pairs = [] #(ratio, quality)
        for i in range(len(quality)):
            pairs.append((wage[i]/quality[i], quality[i]))
        pairs.sort(key=lambda x:x[0])

        maxHeap = [] #qualities
        total_quality = 0
        for ratio, quality in pairs:
            heapq.heappush(maxHeap, -quality)

            total_quality += quality

            if len(maxHeap) > k:
                total_quality += heapq.heappop(maxHeap)

            if len(maxHeap) == k:
                res = min(res, total_quality * ratio)


        return res
        