class Solution {
    private Map createMap(String str) {
        Map<Character, Integer> map = new HashMap<>();
        map.put('L', 0);
        map.put('R', 0);

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            }
        }

        return map;
    }
    public boolean canChange(String start, String target) {
        if (start.equals(target)) return true;

        Map<Character, Integer> startMap = createMap(start);
        Map<Character, Integer> targetMap = createMap(target);

        if (!startMap.equals(targetMap)) {
            return false;
        }

        int i = 0, j = 0;
        int startSize = start.length();
        int targetSize = target.length();

        // i for start and j for target
        while (i < startSize && j < targetSize) {
            while (i < startSize && start.charAt(i) == '_') i++;
            while (j < targetSize && target.charAt(j) == '_') j++;

            if (i == startSize || j == targetSize) break;

            if (start.charAt(i) != target.charAt(j)) {
                return false;
            }
            if (target.charAt(j) == 'L' && !(i >= j)) {
                return false;
            }
            if (target.charAt(j) == 'R' && !(i <= j)) {
                return false;
            }

            i++;
            j++;
        }

        return true;
    }
}