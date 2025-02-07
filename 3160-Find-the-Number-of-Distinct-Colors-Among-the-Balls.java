class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        int[] ans = new int[n];
        Map<Integer, Integer> ballToColor = new HashMap<>();
        Map<Integer, Set<Integer>> colorToBallsSet = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int color = queries[i][1];
            int ball =  queries[i][0];

            if (ball <= limit + 1) {

                if (ballToColor.containsKey(ball)) {
                    int ballColor = ballToColor.get(ball);
                    

                    colorToBallsSet.get(ballColor).remove(ball);
                    
                    if (colorToBallsSet.get(ballColor).isEmpty()) {
                        colorToBallsSet.remove(ballColor);
                    }                  
                }

                ballToColor.put(ball, color);
                colorToBallsSet.computeIfAbsent(color, k -> new HashSet<>()).add(ball);
            }

            ans[i] =  colorToBallsSet.size();
        }
        
        return ans;
    }
}