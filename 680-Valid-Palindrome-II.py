class Solution:
    def validPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1

        while i <= j:
            if s[i] != s[j]:
                left_side, right_side = s[i + 1:j + 1], s[i:j]
                return (left_side == left_side[::-1]
                        or right_side == right_side[::-1])

            i, j = i + 1, j - 1

        return True
