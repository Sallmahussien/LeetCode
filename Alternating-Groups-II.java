public class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int[] extendedColors = new int[colors.length + k - 1];
        for (int i = 0; i < colors.length; i++) {
            extendedColors[i] = colors[i];
        }
        for (int i = 0; i < k - 1; i++) {
            extendedColors[colors.length + i] = colors[i];
        }

        int length = extendedColors.length;
        int result = 0;
        int left = 0;

        for (int right = 1; right < length; right++) {
            if (extendedColors[right] == extendedColors[right - 1]) {
                left = right;
            }

            if (right - left + 1 == k) {
                result++;
                left++;
            }
        }

        return result;
    }
}