class Solution {
    public String pushDominoes(String dominoes) {
        Queue<Integer> directions = new LinkedList<>();
        StringBuilder str = new StringBuilder(dominoes);
        int n = dominoes.length();

        for (int i = 0; i < n; i++) {
            if (dominoes.charAt(i) == 'R' || dominoes.charAt(i) == 'L') {
                directions.offer(i);
            }
        }

        while (!directions.isEmpty()) {
            int idx = directions.poll();
            char direction = str.charAt(idx);

            if (direction == 'L') {
                // left
                if (idx > 0 && str.charAt(idx - 1) == '.') {
                    str.setCharAt(idx - 1, 'L');
                    directions.offer(idx - 1);
                }
            } else {
                // right
                if (idx < (n - 1) && str.charAt(idx + 1) == '.') {
                    if (idx < (n-2) && str.charAt(idx + 2) == 'L') {
                        directions.poll();
                    } else {
                        str.setCharAt(idx + 1, 'R');
                        directions.offer(idx + 1);
                    }
                }
            }

        }

        return str.toString();
    }
}