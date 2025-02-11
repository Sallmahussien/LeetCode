class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder sb = new StringBuilder();
        int n = part.length();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            sb.append(c);

            if (sb.length() >= n && sb.substring(sb.length() - n).equals(part)) {
                sb.delete(sb.length() - n, sb.length());
            }
        }

        return sb.toString();
    }
}