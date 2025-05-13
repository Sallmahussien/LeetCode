class Solution {
    public int lengthAfterTransformations(String s, int t) {
        final int MOD = 1_000_000_007;
        int[] freqArr = new int[26];
        for (char c : s.toCharArray()) {
            freqArr[c - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            int[] nextFreqArr = new int[26];

            for (int idx = 0; idx < 26; idx++) {
                int count = freqArr[idx];
                if (idx < 25) {
                    nextFreqArr[idx + 1] = (nextFreqArr[idx + 1] + count) % MOD;
                } else {
                    nextFreqArr[0] = (nextFreqArr[0] + count) % MOD;
                    nextFreqArr[1] = (nextFreqArr[1] + count) % MOD;
                }
            }

            freqArr = nextFreqArr;
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            ans = (ans + freqArr[i]) % MOD;
        }

        return ans;
    }
}