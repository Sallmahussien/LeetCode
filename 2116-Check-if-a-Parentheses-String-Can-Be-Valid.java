class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if (n % 2 != 0) return false;

        Stack<Integer> openParantheses = new Stack<>();
        Stack<Integer> unlocked = new Stack<>();

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (locked.charAt(i) == '0') {
                unlocked.push(i);
            } else if (c == '(') {
                openParantheses.push(i);
            } else {
                if (!openParantheses.isEmpty()) {
                    openParantheses.pop();
                } else if (!unlocked.isEmpty()) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        while (
            !openParantheses.isEmpty() &&
            !unlocked.isEmpty() &&
            openParantheses.peek() < unlocked.peek()
        ) {
            openParantheses.pop();
            unlocked.pop();
        }

        if (!openParantheses.isEmpty()) return false;

        return unlocked.size() % 2 == 0;

        
    }
}