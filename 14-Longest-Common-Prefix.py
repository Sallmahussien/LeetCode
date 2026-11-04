class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        common_prefix = strs[0]

        for i in range(1, len(strs)):
            j = 0

            while j < min(len(common_prefix), len(strs[i])) and common_prefix[j] == strs[i][j]:
                j += 1

            common_prefix = common_prefix[:j]

            if not common_prefix:
                return ""
           

        return common_prefix
        