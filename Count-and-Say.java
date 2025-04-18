class Solution {
    public String countAndSay(int n) {
        StringBuilder str = new StringBuilder(\1\);

        for (int i = 1; i < n; i++) {
            int l = 0;
            int len = str.length();
            int count = 0;
            StringBuilder sb =  new StringBuilder();

            for (int r = 0; r < len; r++) {
                count++;

                if (r == len - 1 || str.charAt(r) != str.charAt(r + 1)) {
                    sb.append(count).append(str.charAt(r));
                    count = 0;
                }
            }

            str = sb;
        }
 
        return str.toString();
    }
}