class Solution {
    public boolean isValid(String s) {
        Map<Character, Character> parantheses = new HashMap<>();
        parantheses.put(')', '(');
        parantheses.put('}', '{');
        parantheses.put(']', '[');

        Stack<Character> stk = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.isEmpty() || stk.pop() != parantheses.get(c)) {
                    return false;
                }
            }
        }
        return stk.size() == 0;
    }
}