class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int x = 0;

        for (String op : operations) {
            if (op.startsWith("++") || op.endsWith("++")) {
                x++;
            } else {
                x--;
            }
        }

        return x;
        
    }
}