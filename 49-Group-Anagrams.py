class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        sorted_strs_map = {}

        for i, s in enumerate(strs):
            sorted_s = ''.join(sorted(s))
            if not sorted_strs_map.get(sorted_s):
                sorted_strs_map[sorted_s] = [s]
            else:
                sorted_strs_map[sorted_s].append(s)

        result = []

        for strings in sorted_strs_map.values():
            result.append(strings)

        return result