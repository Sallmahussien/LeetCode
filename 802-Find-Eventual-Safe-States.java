class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
         int n = graph.length;
        Map<Integer, Boolean> safe = new HashMap<>();
        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (dfs(i, safe, graph)) {
                res.add(i);
            }
        }

        return res;
    }

    private boolean dfs(int i, Map<Integer, Boolean> safe, int[][] graph) {
        // If we've already determined if the node is safe, return its value
        if (safe.containsKey(i)) {
            return safe.get(i);
        }

        // Mark the node as being visited (assume it's unsafe for now)
        safe.put(i, false);

        // Recursively check all neighbors
        for (int neighbor : graph[i]) {
            if (!dfs(neighbor, safe, graph)) {
                return false;
            }
        }

        // If all neighbors are safe, mark the node as safe
        safe.put(i, true);
        return true;
    }
}