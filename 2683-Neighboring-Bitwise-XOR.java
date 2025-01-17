class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int derivedXor = 0;

        for (int d : derived) {
            derivedXor ^= d;
        }

        return derivedXor == 0;
    }
}