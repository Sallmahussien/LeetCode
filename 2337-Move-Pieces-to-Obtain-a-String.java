class Solution {
    public boolean canChange(String start, String target) {
        if (start.equals(target)) return true;

        int i = 0, j = 0;
        int startSize = start.length();
        int targetSize = target.length();

        while (i < startSize || j < targetSize) {
            while (i < startSize && start.charAt(i) == '_') i++;
            while (j < targetSize && target.charAt(j) == '_') j++;

            if (i == startSize || j == targetSize) {
                return i == startSize && j == targetSize;
            }

            if (start.charAt(i) != target.charAt(j)) {
                return false;
            }
            if (target.charAt(j) == 'L' && !(i >= j)) {
                return false;
            }
            if (target.charAt(j) == 'R' && !(i <= j)) {
                return false;
            }

            i++;
            j++;
        }

        return true;
    }
}