class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            if not self.isAlphanumeric(s[i]):
                i += 1
            elif not self.isAlphanumeric(s[j]):
                j -= 1
            elif s[i].lower() != s[j].lower():
                return False
            else:
                i += 1
                j -= 1

            
        return True

    def isAlphanumeric(self, c):
        return ('a'<= c <= 'z') or ('A' <= c <= 'Z') or ('0' <= c <= '9')

        