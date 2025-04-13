class Solution:
    def countGoodNumbers(self, n: int) -> int:
        even_count = (n + 1) // 2
        odd_count = n // 2
        MOD = 10**9 + 7
        return (pow(5, even_count, MOD) * pow(4, odd_count, MOD)) % MOD
        