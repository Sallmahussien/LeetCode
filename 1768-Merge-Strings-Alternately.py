class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n1, n2 = len(word1), len(word2)
        max_length = max(n1, n2)
        result = []

        for i in range(max_length):
            if i < n1:
                result.append(word1[i])

            if i < n2:
                result.append(word2[i])
        
        return "".join(result)