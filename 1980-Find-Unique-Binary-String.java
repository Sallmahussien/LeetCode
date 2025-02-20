class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums[0].length();
        Set<String> numsSet = new HashSet<>();
        
        for (String num : nums) {
            numsSet.add(num);
        }

        StringBuilder sb = new StringBuilder();

        generateBinary(n, "", numsSet, sb);

        return sb.toString();
    }

    void generateBinary(int n, String s, Set<String> numsSet, StringBuilder sb) {
        if (sb.length() != 0) return;

        if (s.length() == n) {
            if (!numsSet.contains(s)) sb.append(s);
            return;
        }

        generateBinary(n, s + "0", numsSet, sb);
        generateBinary(n, s + "1", numsSet, sb);
    }
}