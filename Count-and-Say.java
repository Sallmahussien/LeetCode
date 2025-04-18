class Solution {
    public String countAndSay(int n) {
        StringBuilder str = new StringBuilder(\1\);

        for (int i = 1; i < n; i++) {
            int len = str.length();
            int count = 0;
            StringBuilder sb =  new StringBuilder();

            for (int j = 0; j < len; j++) {
                count++;

                if (j == len - 1 || str.charAt(j) != str.charAt(j + 1)) {
                    sb.append(count).append(str.charAt(j));
                    count = 0;
                }
            }

            str = sb;
        }
 
        return str.toString();
    }
}