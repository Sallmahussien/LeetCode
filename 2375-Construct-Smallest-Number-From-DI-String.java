class Solution {
    public String smallestNumber(String pattern) {
        Stack<Integer> stk = new Stack<>();
        StringBuilder sb = new StringBuilder();
        int n = pattern.length();

        for (int i = 0; i < n + 1; i++) {
            stk.push(i + 1);

            while ((i == n || pattern.charAt(i) == 'I') && !stk.isEmpty()) {
                sb.append(stk.pop());
            }
        }

        return sb.toString();
        
    }
}