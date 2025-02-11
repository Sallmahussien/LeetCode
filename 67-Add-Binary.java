class Solution {
    public String addBinary(String a, String b) {
        char carry = '0';
        StringBuilder sb = new StringBuilder();
        int onesCount = 0;

        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0) {
            onesCount = 0;

            if (i >= 0 && a.charAt(i) == '1') onesCount++;
            if (j >= 0 && b.charAt(j) == '1') onesCount++;
            if (carry == '1') onesCount++;


            if (onesCount == 0) {
                sb.append('0');
            } else if (onesCount == 1) {
                sb.append('1');
                carry = '0';
            } else if (onesCount == 2) {
                sb.append('0');
                carry = '1';
            } else {
                sb.append('1');
                carry = '1';
            }

            i--;
            j--;
        }

        if (carry == '1') sb.append('1');

        return sb.reverse().toString();
    }
}