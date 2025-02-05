class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int diffCount = 0;
        char firstS1 = 0, firstS2 = 0, secondS1 = 0, secondS2 = 0;

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diffCount++;
                
                if (diffCount == 1) {
                    firstS1 = s1.charAt(i);
                    firstS2 = s2.charAt(i);
                } else if (diffCount == 2) {
                    secondS1 = s1.charAt(i);
                    secondS2 = s2.charAt(i);
                } else {
                    return false;
                }
            }
        }

        return diffCount == 0 || (diffCount == 2 && firstS1 == secondS2 && firstS2 == secondS1);
    }
}