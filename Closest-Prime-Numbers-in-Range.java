class Solution {
    public int[] closestPrimes(int left, int right) {
        List<Integer> primes = new ArrayList<>();

        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.add(i);
            }
        }

        if (primes.size() < 2) return new int[]{-1, -1};

        int diff = primes.get(1) - primes.get(0);
        int[] ans = new int[]{primes.get(0), primes.get(1)};

        for (int i = 2; i < primes.size(); i++) {
            if (primes.get(i) - primes.get(i-1) < diff) {
                diff = primes.get(i) - primes.get(i-1);
                ans[0] = primes.get(i-1);
                ans[1] = primes.get(i);
            }
        }

        return ans;
    }

    private boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
}