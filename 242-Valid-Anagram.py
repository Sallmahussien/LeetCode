class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        arr = [0] * 26
        for c in s:
            arr[ord(c) - ord('a')] += 1

        for c in t:
            arr[ord(c) - ord('a')] -= 1

        for i in arr:
            if i != 0:
                return False

        return True
                 